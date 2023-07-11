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
    bool pathSum(TreeNode *root, int targetSum, int currSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (!root->left && !root->right)
        {
            currSum += root->val;
            if (currSum == targetSum)
            {
                return true;
            }
        }
        return pathSum(root->left, targetSum,root->val+currSum) || pathSum(root->right, targetSum,root->val+currSum);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int currSum = 0;
        return pathSum(root, targetSum, currSum);
    }
};

int main(void)
{
    vector<int> values = {5, 4, 8, 11, NULL, 13, 4, 7, 2, NULL, NULL, NULL, 1};
    TreeNode *root = createTree(values, 0);
    int targetSum = 22;
    Solution s;
    cout << s.hasPathSum(root, targetSum) << endl;
}