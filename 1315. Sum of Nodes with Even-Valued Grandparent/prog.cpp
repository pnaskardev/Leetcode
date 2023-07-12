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
    int sum = 0;
    void calculate(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (root->val % 2 == 0)
        {
            if (root->left)
            {
                if (root->left->left)
                {
                    sum += root->left->left->val;
                }
                if (root->left->right)
                {
                    sum += root->left->right->val;
                }
            }
            if (root->right)
            {
                if (root->right->left)
                {
                    sum += root->right->left->val;
                }
                if (root->right->right)
                {
                    sum += root->right->right->val;
                }
            }
        }
        calculate(root->left);
        calculate(root->right);
    }

public:
    int sumEvenGrandparent(TreeNode *root)
    {
        calculate(root);
        return sum;
    }
};

int main(void)
{
    vector<int> values = {6, 7, 8, 2, 7, 1, 3, 9, NULL, 1, 4, NULL, NULL, NULL, 5};
    TreeNode *root = createTree(values, 0);
    Solution s;
    cout << s.sumEvenGrandparent(root) << endl;
}