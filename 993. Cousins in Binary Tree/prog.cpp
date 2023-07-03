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
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty()==false)
        {
            int n=q.size();
            bool x_found=false;
            bool y_found=false;

            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();

                if(temp->val==x)
                    x_found=true;
                if(temp->val==y)
                    y_found=true;
                
                if(temp->left!=NULL && temp->right!=NULL)
                {
                    if(temp->left->val==x && temp->right->val==y)
                        return false;
                    if(temp->left->val==y && temp->right->val==x)
                        return false;
                }

                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }

            }

            if(x_found==true && y_found==true)
                return true;
        }
        return false;
    }
};

int main(void)
{
    vector<int> values = {1, 2, 3, 4};
    TreeNode *root = createTree(values, 0);
    Solution s;
    cout << s.isCousins(root, 4, 3);
}