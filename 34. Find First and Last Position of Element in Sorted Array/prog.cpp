#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{

private:
    int lower_bound(vector<int>nums,int target)
    {
        int n=nums.size();
        int l=0,r=n-1;
        int ans= -1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                r=mid-1;
            }
            else if(nums[mid]>target)
            {   
                r=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
        }
        return ans;
    }


    int upper_bound(vector<int>nums,int target)
    {
        int n=nums.size();
        int l=0,r=n-1;
        int ans= -1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
            {   
                r=mid-1;
            }
            else if(nums[mid]<=target)
            {
                l=mid+1;
            }
        }
        return ans;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        
        // if(nums.size()==0)
        // {
        //     return {0};
        // }
        return {lower_bound(nums,target),upper_bound(nums,target)};
    }
};
int main(void)
{
    vector<int>arr={5,7,7,8,8,10};
    int target=8;
    Solution ob;
    auto res=ob.searchRange(arr,target);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}