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
    int l, r;
    int sum = 0;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        dfs(root->left);
        if (root->val >= l && root->val <= r)
        {
            sum += root->val;
        }
        dfs(root->right);
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        l = low;
        r = high;
        dfs(root);
        return sum;
    }
};

int main(void)
{
    vector<int> arr = {10, 5, 15, 3, 7, NULL, 18};
    TreeNode *root = createTree(arr, 0);
    Solution ob;
    cout << ob.rangeSumBST(root, 7, 15) << endl;
}