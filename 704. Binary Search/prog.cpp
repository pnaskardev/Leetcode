#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int search(vector<int>& nums, int target) 
        {
            int n=nums.size();
            int l=0,r=n-1,ans=-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(nums[mid]==target)
                {
                    ans=mid;
                    break;
                }
                if(nums[mid]<target)
                {
                    l=mid+1;
                }
                if(nums[mid]>target)
                {
                    r=mid-1;
                }
            }
            // cout<<ans<<endl;
            return ans;
        }
};
int main(void)
{
    vector<int>nums={-1,0,3,5,9,12};
    int target=9;
    Solution ob;
    // ob.search(nums,target);
    cout<<ob.search(nums,target)<<endl;
}