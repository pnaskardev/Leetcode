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
    long long int firstMinimum, secondMinimum = LONG_LONG_MAX;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (root->val > firstMinimum)
            if (root->val <= secondMinimum)
                secondMinimum = root->val;

        dfs(root->left);
        dfs(root->right);
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        firstMinimum = root->val;
        dfs(root);
        if (secondMinimum == LONG_LONG_MAX)
            return -1;
        return secondMinimum;
    }
};

int main(void)
{
    vector<int> arr = {2, 2, 5, NULL, NULL, 5, 7};
    TreeNode *root = createTree(arr, 0);

    Solution ob;
    cout << ob.findSecondMinimumValue(root) << endl;
}