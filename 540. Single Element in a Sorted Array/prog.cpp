#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        auto pred = [&](int i)
        {
            return (nums[i] == nums[i + 1]);
        };
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else
        {
            int l = 0, r = nums.size() - 1;
            while (r - l > 1)
            {
                int mid = (l + r) / 2;
                if (mid % 2 == 1)
                {
                    mid--;
                }
                if (pred(mid))
                {
                    l = mid + 2;
                }
                else
                {
                    r = mid;
                }
            }
            // cout << l << endl;
            return nums[l];
        }
    }
};

int main(void)
{
    // vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    vector<int> arr = {1, 2, 2, 3, 3};
    Solution ob;
    cout << ob.singleNonDuplicate(arr) << endl;
}