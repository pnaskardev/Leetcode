#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int minim=1e8;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
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
                if(sum==target)
                {
                    return sum;
                }
                if(abs(sum-target)<abs(minim-target))
                {
                    minim=sum;
                }
                else if(sum>target)
                {
                    right--;
                }
                else
                {
                    // res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                }
            }
        }
        return minim;
    }
};
int main(void)
{
    vector<int>arr={-1,2,1,-4};
    vector<int>arr1={0,0,0};
    vector<int>arr2={1,1,1,0};
    int target=-100;
    Solution ob;
    cout<<ob.threeSumClosest(arr2,target)<<endl;
}