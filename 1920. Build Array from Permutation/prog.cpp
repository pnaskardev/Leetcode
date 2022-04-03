#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        vector<int>res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            res[i]=nums[nums[i]];
        }
        return res;
    }
};
int main(void)
{
    vector<int>nums={0,2,1,5,3,4};
    Solution ob;
    auto res=ob.buildArray(nums);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}