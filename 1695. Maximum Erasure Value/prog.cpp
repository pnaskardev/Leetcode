#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int curr_sum = 0, max_sum = 0,left=0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            while (s.find(nums[i])!=s.end())
            {
                s.erase(nums[left]);
                curr_sum-=nums[left];
                left++;
            }
            curr_sum += nums[i];
            s.insert(nums[i]);
            max_sum=max(curr_sum,max_sum);
        }
        return max_sum;
    }
};
int main(void)
{
    vector<int> arr = {4, 2, 4, 5, 6};
    Solution ob;
    cout << ob.maximumUniqueSubarray(arr) << endl;
}