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
    private:
        int average(TreeNode *root,int &v)
        {
            if(root==NULL)
            {
                return 0;
            }
            v++;
            int left=average(root->left,v);
            int right=average(root->right,v);
            int sum=left+right+root->val;
            return sum;
        }
    public:
        int averageOfSubtree(TreeNode* root) {
            if(root==NULL)
            {
                return 0;
            }
            int count=0,v=0;
            int sum=average(root,v);
            if(root->val==(sum/v))
            {
                count++;
            }
            averageOfSubtree(root->left);
            averageOfSubtree(root->right);
            return count;
        }
};

int main(void)
{
    vector<int>arr={4,8,5,0,1,NULL,6};
    TreeNode *root=createTree(arr,0);
    Solution ob;
    cout<<ob.averageOfSubtree(root)<<endl;
}