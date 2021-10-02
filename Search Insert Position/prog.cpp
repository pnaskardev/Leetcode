#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int start=0,end=nums.size()-1,ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                ans=mid;
                start=mid+1;
            }
        }
        if(target<nums[ans])
        {
            return ans;
        }
        return ans+1;
    }
};
int main(void)
{
    vector<int>arr={1,3,5,6};
    vector<int>arr1={1,3,5,6};
    int target=2;
    Solution ob;
    cout<<ob.searchInsert(arr,target)<<endl;
}