#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};
int main(void)
{
    vector<int>nums={1,2,3,4,4,3,2,1};
    vector<int>nums2={1,1,2,2};
    Solution ob;
    auto result=ob.shuffle(nums2,nums2.size()/2);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}