#include<iostream>
#include<bits/stdc++.h>
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
        TreeNode* invertTree(TreeNode* root) 
        {
            if(root==NULL)
                return NULL;
            invertTree(root->left);
            invertTree(root->right);

            // time to swap the roots
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
            return root;
        }
};

void inorder(TreeNode* r)
{
    if(r==NULL)
        return;
    inorder(r->left);
    cout<<r->val<<" ";
    inorder(r->right);
}
int main(void)
{
    vector<int>root={4,2,7,1,3,6,9};
    TreeNode *r=createTree(root,0);
    Solution s;
    TreeNode* ans=s.invertTree(r);
    inorder(ans);

}