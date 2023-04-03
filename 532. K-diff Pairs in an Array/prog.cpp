#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int findPairs(vector<int>& nums, int k) 
        {
            int ans=0;
            sort(nums.begin(),nums.end());
            unordered_map<int,int>mp;
            for(auto i:nums)
            {
                mp[i]++;
            }
            if(k!=0)
            {
                // for(int i=0;i<nums.size();i++)
                // {
                //     if(mp.find(nums[i]+k)!=mp.end())
                //     {
                //         ans++;  
                //     }
                // }
                for(auto i:mp)
                {
                    if(mp.find(i.first+k)!=mp.end())
                    {
                        ans++;
                    }
                }
            }
            else
            {
                for(auto i:mp)
                {
                    if(i.second>1)
                    {
                        ans++;
                    }
                }
            }
            return ans;
        }
};
int main(void)
{
    int k=2;
    vector<int>nums={3,1,4,1,5};
    Solution ob;
    cout<<ob.findPairs(nums,k)<<endl;
}