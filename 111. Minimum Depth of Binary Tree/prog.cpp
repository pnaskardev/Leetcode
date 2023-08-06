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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftAns = minDepth(root->left);
        int rightAns = minDepth(root->right);

        return 1+ (min(leftAns,rightAns) ? min(leftAns,rightAns): max(leftAns,rightAns));
    }
};

int main(void)
{
    vector<int> arr = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode *root = createTree(arr, 0);
    Solution ob;
    cout << ob.minDepth(root) << endl;
}