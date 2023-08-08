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

class Solution
{
private:
    bool dfs(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL and root2 == NULL)
            return true;
        if (root1 == NULL or root2 == NULL)
            return false;
        
        return root1->val==root2->val and dfs(root1->left,root2->right) and dfs(root1->right, root2->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        dfs(root->left, root->right);
    }
};

int main(void)
{
    vector<int> arr = {1, 2, 2, 3, 4, 4, 3};
    TreeNode *root = createTree(arr, 0);
    Solution s;
    cout << s.isSymmetric(root);
}