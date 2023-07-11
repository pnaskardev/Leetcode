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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<int, TreeNode *> parent;
        queue<TreeNode *> q;
        q.push(root);
        // First BFS to create parent children relationship
        while (q.empty() == false)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto top = q.front();
                q.pop();
                if (top->left)
                {
                    q.push(top->left);
                    parent[top->left->val] = top;
                }
                if (top->right)
                {
                    q.push(top->right);
                    parent[top->right->val] = top;
                }
            }
        }

        // Second BFS to find the nodes at distance k

        unordered_map<int, int> visited;
        q.push(target);
        while (k-- && q.empty() == false)
        {
            // this much was to find all the nodes at k distance below the
            // target node
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto top = q.front();
                q.pop();
                // setting visited =true
                visited[top->val] = 1;
                if (top->left && visited[top->left->val] == 0)
                {
                    q.push(top->left);
                }
                if (top->right && visited[top->right->val] == 0)
                {
                    q.push(top->right);
                }

                // this much was to find the parent of the target node
                if (parent[top->val] && visited[parent[top->val]->val] == 0)
                {
                    q.push(parent[top->val]);
                }
            }
        }
        // when k becomes 0 then we have to return the nodes at distance k
        // inside the Queue
        vector<int> ans;
        while (q.empty() == false)
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

int main(void)
{
    vector<int> values = {3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4};
    TreeNode *target = new TreeNode(5);
    int k = 2;
    TreeNode *root = createTree(values, 0);
    Solution s;
    vector<int> ans = s.distanceK(root, target, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}