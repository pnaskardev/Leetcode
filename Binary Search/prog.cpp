#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start=0,end=nums.size()-1,ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                return mid;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
        }
        return ans;   
    }
};
int main(void)
{
    vector<int> arr={-1,0,3,5,9,12};
    int target=9;
    Solution ob;
    cout<<ob.search(arr,target)<<endl;
    
}