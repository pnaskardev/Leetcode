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
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->val == 0)
            return false;
        if (root->val == 1)
            return true;
        if (root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
        // if (root->val == 3)
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};

int main(void)
{
    vector<int> arr = {2, 1, 3, NULL, NULL, 0, 1};
    TreeNode *root = createTree(arr, 0);
    Solution ob;
    cout << ob.evaluateTree(root) << endl;
}