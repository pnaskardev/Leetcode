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
    TreeNode *ans;
    void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr || cloned == nullptr)
        {
            return;
        }
        if (cloned->val == target->val)
        {
            ans = cloned;
        }
        dfs(original, cloned->left, target);
        dfs(original, cloned->right, target);
    }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        dfs(original, cloned, target);
        return ans;
    }
};

int main(void)
{
    vector<int> arr = {7, 4, 3, NULL, NULL, 6, 19};
    int target = 3;
    TreeNode *root = createTree(arr, 0);
}