#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l=0,r=nums.size()-1,ans;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        } 
        return l;
    }
};
int main(void)
{
    vector<int>arr={1,3,5,6};
    Solution ob;
    cout<<ob.searchInsert(arr,2)<<endl;
}