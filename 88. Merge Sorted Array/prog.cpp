#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans;
        int p = 0, q = 0;
        while (p < nums1.size() && q < nums2.size())
        {
            // cout << p << " " << q << endl;
            if (nums1[p] <= nums2[q])
            {
                cout << nums1[p] << " " << nums2[q] << endl;
                ans.push_back(nums1[p]);
                p++;
            }
            else
            {
                ans.push_back(nums2[q]);
                q++;
            }
        }
        if (p == nums1.size())
        {
            for (int i = q; i < nums2.size(); i++)
            {
                ans.push_back(nums2[i]);
            }
        }
        else
            for (int i = p; i < nums1.size(); i++)
            {
                ans.push_back(nums1[i]);
            }

        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        nums1.clear();
        nums1 = ans;
    }
};
int main(void)
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution obj;
    obj.merge(nums1, nums1.size(), nums2, nums2.size());
    // for (auto i : nums1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
}