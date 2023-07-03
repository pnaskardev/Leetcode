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

class Solution {

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL && root2==NULL)
            return NULL;
        if(root1==NULL)
            return root2;
        if(root2==NULL)
            return root1;
        TreeNode* ans=new TreeNode(root1->val+root2->val);
        ans->left=mergeTrees(root1->left,root2->left);
        ans->right=mergeTrees(root1->right,root2->right);
        return ans;
    }
};

int main(void)
{
    vector<int>root1={1,3,2,5},root2={2,1,3,NULL,4,NULL,7};
    TreeNode *r1=createTree(root1,0);
    TreeNode *r2=createTree(root2,0);
    Solution s;
    
}