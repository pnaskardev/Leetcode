#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (j < nums.size())
        {
            sum += nums[j];
            while (sum >= target)
            {
                sum -= nums[i];
                ans = min(ans, j - i + 1);
                i++;
            }
            j++;
        }
        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};

int main(void)
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution sol;
    cout << sol.minSubArrayLen(7, nums);
}