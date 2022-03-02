#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    int findPairs(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        unordered_map<int,int>::iterator it;
        int counter=0;
        for(int i=0;i<n;i++)
        {
           mp[nums[i]]++;
        }
        for(auto i:mp)
        {
            if(k==0)
            {
                if(i.second>1)
                {
                    // cout<<i.first<<" "<<i.first+k<<endl;
                    counter++;
                }
            }
            else if(mp.find(i.first+k)!=mp.end())
            {
                // cout<<i.first<<" "<<i.first+k<<endl;
                counter++;
            }
            
        }
        return counter;
    }
};
int main(void)
{
    vector<int>nums1={3,1,4,1,5};
    vector<int>nums2={1,2,3,4,5};
    vector<int>nums3={1,3,1,5,4};
    vector<int>nums4={1,2,4,4,3,3,0,9,2,3};
    int k=2;
    Solution ob;
    cout<<ob.findPairs(nums3,0)<<endl;

}