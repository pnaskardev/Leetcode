#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            // Condition if there are a lot of duplicate values
            // in the front of the array
            // we need the last occurence of the duplicate number
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int left=i+1,right=nums.size()-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                // cout<<nums[i]<<" "<<nums[left]<<" "<<nums[right]<<endl;
                if(sum<0)
                {
                    left++;
                }
                else if(sum>0)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while(left<right && nums[left]==nums[left-1])
                    {
                        left++;
                    }
                    right--;
                    while(left<right && nums[right]==nums[right+1])
                    {
                        right--;
                    }
                }
            }
            // cout<<endl;
        }
        return res;
    }
};

int main(void)
{
   vector<int>arr={-1,0,1,2,-1,-4};
   vector<int>arr1={-2,0,1,1,2};
   Solution ob;
   auto res=ob.threeSum(arr);
   for(int i=0;i<res.size();i++)
   {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
   }
   cout<<endl;
}