#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// create tree from array
TreeNode *createTree(const vector<int> &values, int index)
{
    if (index >= values.size() || values[index] == NULL)
    {
        return nullptr;
    }

    TreeNode *node = new TreeNode(values[index]);
    node->left = createTree(values, 2 * index + 1);
    node->right = createTree(values, 2 * index + 2);

    return node;
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

class Solution
{

public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return NULL;
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->val = root1->val + root2->val;
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

int main(void)
{
    vector<int> arr1 = {1, 3, 2, 5}, arr2 = {2, 1, 3, NULL, 4, NULL, 7};
    TreeNode *root1 = createTree(arr1, 0);
    TreeNode *root2 = createTree(arr2, 0);

    Solution ob;
    TreeNode *ans = ob.mergeTrees(root1, root2);
    inorder(ans);
}