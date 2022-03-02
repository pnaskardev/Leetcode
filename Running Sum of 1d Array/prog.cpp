#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=0;
        vector<int>ans(nums.size());
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans[i]=sum;
        }
        return ans;
    }
};
int main(void)
{
    vector<int>nums={1,2,3,4};
    Solution ob;
    auto ans=ob.runningSum(nums);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}