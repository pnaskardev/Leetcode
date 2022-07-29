#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int rep=nums[0];
        int j=1;
        vector<int>arr;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=rep)
            {
                rep=nums[i];
                nums[j]=nums[i];
                j++;
            }
        }
        // for(auto i:nums)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return j;
    }
};
int main(void)
{
    vector<int>arr={1,1,2};
    vector<int>arr1={0,0,1,1,1,2,2,3,3,4};

    Solution ob;
    cout<<ob.removeDuplicates(arr1)<<endl;
}