#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        bool ans=false;
        if(k==0 || n==1)
        {
            ans=false;
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                if(mp.find(nums[i])!=mp.end())
                {
                    if(abs(i-mp[nums[i]])<=k)
                    {
                        ans=true;
                        break;
                    }
                }
                mp[nums[i]]=i;
            }
        }   
        return ans;
    }
};
int main(void)
{
    vector<int>arr={1,2,3,1};
    vector<int>arr1={1,0,1,1};
    vector<int>arr2={1,2,3,1,2,3};
    int k=3;
    Solution ob;
    cout<<ob.containsNearbyDuplicate(arr2,2)<<endl;
}