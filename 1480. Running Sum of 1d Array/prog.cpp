#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        vector<int>res;
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
            res.push_back(sum);
        }
        return res;
    }
};
int main(void)
{
    vector<int>nums={1,2,3,4};
    Solution ob;
    auto res=ob.runningSum(nums);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}