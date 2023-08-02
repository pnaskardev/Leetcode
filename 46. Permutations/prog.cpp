#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    void backtrack(int start, vector<int> &nums)
    {
        if (start == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            backtrack(start + 1, nums);
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        backtrack(0,nums);
        return ans;
    }
};

int main(void)
{
    vector<int> nums = {1, 2, 3};
    Solution obj;
    vector<vector<int>> ans = obj.permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}