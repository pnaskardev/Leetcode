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
    void dfs(TreeNode*& ans, TreeNode* root) {
        if (!root) return;
        dfs(ans, root->left);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        dfs(ans, root->right);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp;
        TreeNode* ans = new TreeNode();
        temp = ans;
        dfs(ans, root);
        return temp->right;
    }
};



int main(void)
{
    vector<int> arr = {5, 3, 6, 2, 4, NULL, 8, 1, NULL, NULL, NULL, 7, 9};
    TreeNode *root = createTree(arr, 0);
    Solution ob;
    TreeNode *ans = ob.increasingBST(root);
}