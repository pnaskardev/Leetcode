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
    int max_freq = 0, curr_freq = 0, prev_elem = INT_MIN;
    vector<int> arr;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;

        dfs(root->left);

        int current_element = root->val;
        if (current_element == prev_elem)
            curr_freq++;
        else
            curr_freq = 1;

        if (curr_freq == max_freq)
            arr.emplace_back(current_element);
        else if (curr_freq > max_freq)
        {
            max_freq = curr_freq;
            arr.clear();
            arr.emplace_back(current_element);
        }
        prev_elem = current_element;

        dfs(root->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        if (root == NULL)
            return vector<int>();
        dfs(root);
        return arr;
    }
};

int main(void)
{
    vector<int> arr = {1, NULL, 2, 2};
    TreeNode *root = createTree(arr, 0);

    Solution ob;
    auto res = ob.findMode(root);
}