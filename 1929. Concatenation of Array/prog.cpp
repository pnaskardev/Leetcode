#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int>ans(2*nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=nums[i];
            ans[i+nums.size()]=nums[i];
        }
        return ans;
    }
};
int main(void)
{
    vector<int>nums={1,2,1};
    Solution ob;
    auto res=ob.getConcatenation(nums);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}