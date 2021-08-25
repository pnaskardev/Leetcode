#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        unordered_map<int,int>::iterator it;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                it=mp.find(nums[i]);
                if(abs(i-it->second)<=k)
                {
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};
int32_t main(void)
{
    vector<int>arr1={1,2,3,1};  
    vector<int>arr2={1,0,1,1};    
    vector<int>arr3={1,2,3,1,2,3};
    Solution ob;
    cout<<ob.containsNearbyDuplicate(arr2,1)<<endl;
}