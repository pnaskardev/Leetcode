#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int OtherPart=target-nums[i];
            if(mp.find(OtherPart)!=mp.end())
            {
                ans={i,mp[OtherPart]};
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};

int main(void)
{
    vector<int>arr={2,7,11,15};
    vector<int>arr1={3,2,4};
    vector<int>arr2={3,3};
    int target=9;
    Solution ob;
    auto res=ob.twoSum(arr2,6);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}