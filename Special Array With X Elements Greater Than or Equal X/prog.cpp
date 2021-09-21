#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    int find(int x,vector<int>&nums)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=x)
            {
                c++;
            }
        }
        return c;
    }
public:
    int specialArray(vector<int>& nums) 
    {
        int start=0;
        int end=nums.size();
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int res=find(mid,nums);
            if(mid==res)
            {
                return res;
            }
            else if(res<mid)
            {
                end=mid-1;
            }
            else if( res>mid)
            {
                start=mid+1;
            }
        }
        return -1;
    }
};
int main(void)
{
    vector<int>arr={3,5};
    vector<int>arr1={0,0};
    vector<int>arr2={0,4,3,0,4};
    vector<int>arr3={3,6,7,7,0};
    Solution ob;
    cout<<ob.specialArray(arr3)<<endl;
}