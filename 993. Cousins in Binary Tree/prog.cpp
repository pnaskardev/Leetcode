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
        while (q.empty() == false)
        {
            int n = q.size();
            bool x_found = false;
            bool y_found = false;

            for (int i = 0; i < n; i++)
            {
                TreeNode *top = q.front();
                q.pop();

                if (top->val == x)
                {
                    x_found = true;
                }
                else if (top->val == y)
                {
                    y_found = true;
                }

                if (top->left != NULL && top->right != NULL)
                {
                    if (top->left->val == x && top->right->val == y)
                        return false;
                    if (top->left->val == y && top->right->val == x)
                        return false;
                }

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            if (x_found && y_found)
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