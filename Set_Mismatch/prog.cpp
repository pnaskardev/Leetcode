#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
class Solution {
public:
    // vector<int> findErrorNums(vector<int>& nums) 
    vector<int> findErrorNums(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        vector<int>res;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]++;
                sum+=nums[i];
            }
            else
            {
                res.push_back(nums[i]);
            }
        }
        int n=nums.size();
        int comp=n*(n+1)/2;
        res.push_back(comp-sum);
        return res;

    }
};
int32_t main(void)
{
    vector<int>arr1={1,2,2,4};  
    vector<int>arr2={1,1};    
    Solution ob;
    ob.findErrorNums(arr1);
}