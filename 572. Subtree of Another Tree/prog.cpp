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
    bool ans = false;
    bool dfs(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL and subRoot == NULL)
            return true;
        if (root == NULL || subRoot == NULL)
            return false;

        if (root->val == subRoot->val)
        {
            bool left = dfs(root->left, subRoot->left);
            bool right = dfs(root->right, subRoot->right);
            return left & right;
        }
        return false;
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL)
            return false;
        if (dfs(root, subRoot) == true)
            return true;
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left or right;
    }
};

int main(void)
{
}