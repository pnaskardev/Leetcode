#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            int l = -1, r = nums.size();
            while (r - l > 1)
            {
                int mid = (l + r) / 2;
                if (nums[mid] <= target)
                    l = mid;
                else
                    r = mid;
            }
            if (l >= 0 && nums[l] == target)
            {
                return l;
            }
            return -1;
        }
    }
};

int main(void)
{
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    Solution obj;
    cout << obj.search(arr, 2) << endl;
}