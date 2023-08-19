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
    int sum = 0;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        dfs(root);
        return root;
    }
};

int main(void)
{
    vector<int> values = {4, 1, 6, 0, 2, 5, 7, NULL, NULL, NULL, 3, NULL, NULL, NULL, 8};
    TreeNode *root = createTree(values, 0);
    Solution s;
    auto res = s.bstToGst(root);
}