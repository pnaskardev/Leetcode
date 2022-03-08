#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto i:mp)
        {
            if(i.second>=2)
            {
                int n=i.second;
                ans+=(n*(n-1))/2;
            }
        }
        return ans;
    }
};
int main(void)
{
    vector<int>arr={1,2,3,1,1,3};
    Solution ob;
    cout<<ob.numIdenticalPairs(arr)<<endl;
}