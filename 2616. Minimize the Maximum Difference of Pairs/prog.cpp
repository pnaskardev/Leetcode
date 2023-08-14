#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool possible(vector<int> &nums, int diff, int p)
    {
        int counter = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (abs(nums[i] - nums[i + 1]) <= diff)
            {
                counter++;
                i++;
            }
            if (counter >= p)
            return true;
        }
        return false;
    }

public:
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[nums.size() - 1] - nums[0];
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (possible(nums, mid, p) == true)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(void)
{
    vector<int> arr = {10, 1, 2, 7, 1, 3};
    Solution ob;
    cout << ob.minimizeMax(arr, 2) << endl;
}