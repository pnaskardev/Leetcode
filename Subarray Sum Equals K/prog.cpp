#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int subarraySum(vector<int>& nums, int k) 
        {
            int n=nums.size();
            vector<int>prefix(n);
            unordered_map<int,int>mp;
            int sum=0,counter=0;
            prefix[0]=nums[0];
            for(int i=1;i<n;i++)
            {
                prefix[i]=nums[i]+prefix[i-1];
            }
            // for(auto i:prefix)
            // {
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            for(int i=0;i<n;i++)
            {
                if(prefix[i]==k)
                {
                    counter++;
                }
                if(mp.find(prefix[i]-k)!=mp.end())
                {
                    counter+=mp[prefix[i]-k];
                }
                mp[prefix[i]]++;
            }
            return counter;
        }
};
int main(void)
{
    vector<int>nums={1,1,1};
    vector<int>nums1={1,2,3};
    vector<int>nums2={1,2,1,2,1};
    vector<int>nums3={1};
    int k=3;
    Solution ob;
    // ob.subarraySum(nums1,k);
    cout<<ob.subarraySum(nums2,k)<<endl;
}