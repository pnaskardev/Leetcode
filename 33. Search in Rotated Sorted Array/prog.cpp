#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int l=0,r=nums.size()-1;
        if(nums[n-1]<target)
        {
            while(l<r)
            {
                int mid=l+(r-l+1)/2;
                if(nums[mid]>target || nums[mid]<=nums[n-1])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid;
                }

            }
        }
        else
        {
            while(l<r)
            {
                int mid=l+(r-l)/2;
                if(nums[mid]>nums[n-1] || nums[mid]<target)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid;
                }
            }
        }
        if(nums[l]==target)
        {
            return l;
        }
        return -1;
    }
};

int main(void)
{
    
}