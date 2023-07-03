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

class Solution
{
private:
    int sum = 0;
    int L, R;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left);
        // cout << root->val << " ";
        if (root->val >= L && root->val <= R)
            sum += root->val;
        inorder(root->right);
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        L = low, R = high;
        inorder(root);
        return sum;
    }
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

int main(void)
{
    vector<int> values = {10, 5, 15, 3, 7, NULL, 18};
    TreeNode *root = createTree(values, 0);
    // inorder(root);
    Solution ob;
    cout << ob.rangeSumBST(root, 7, 15) << endl;
}