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
    int deepestLeavesSum(TreeNode *root)
    {
        vector<vector<int>> levels;
        vector<int>level;
        if (root == nullptr)
        {
            return 0;
        }
        // TreeNode* current;
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty())
        {
            auto current = q.front();
            q.pop();
            if (current)
            {
                level.push_back(current->val);
                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
            }
            else
            {
                levels.push_back(level);
                level.clear();
                if(!q.empty())
                {
                    q.push(nullptr);
                }
            }
        }
        int n=levels.size()-1;
        vector<int>lastLevel=levels[n];
        int sum=accumulate(lastLevel.begin(),lastLevel.end(),0);
        return sum;
    }
};

int main(void)
{
    vector<int> values = {1, 2, 3, 4, 5, NULL, 6, 7, NULL, NULL, NULL, NULL, 8};
    Solution s;
    TreeNode *root = createTree(values, 0);
    cout << s.deepestLeavesSum(root) << endl;
}