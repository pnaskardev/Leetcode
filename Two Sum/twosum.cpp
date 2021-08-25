#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>res;
        map<int,int>mp;
        map<int,int>::iterator it;
        for(int i=0;i<nums.size();i++)
        {
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end())
            {
                it=mp.find(rem);
                res.push_back(it->second);
                res.push_back(i);
               
            }
            else
            {
                mp.insert({nums[i],i});
            }
        }
        return res;
    }
};
int main(void)
{
    vector<int>arr={2,7,11,15};
    int target=9;
    Solution ob;
    vector<int>res=ob.twoSum(arr,target);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}