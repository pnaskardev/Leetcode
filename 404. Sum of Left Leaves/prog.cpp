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
    int ans = 0;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
        {
            ans+=root->left->val;
            // cout<<root->val<<" ";
        }
        inorder(root->left);
        inorder(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        inorder(root);
        return ans;
    }
};

int main(void)
{
    vector<int> values = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode *root = createTree(values, 0);

    Solution s;
    cout << s.sumOfLeftLeaves(root) << endl;
}