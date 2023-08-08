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
    bool isValid = true;
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if(isValid and abs(leftHeight-rightHeight)>1)
            isValid=false;
        return 1+max(leftHeight,rightHeight);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        height(root);
        return isValid;
    }
};

int main(void)
{
    vector<int> values = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode *root = createTree(values, 0);
    Solution s;
    cout << s.isBalanced(root) << endl;
}