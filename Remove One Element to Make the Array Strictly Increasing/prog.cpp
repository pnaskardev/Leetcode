#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int counter=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>=nums[i])
            {
                if(counter==1)
                {
                    return false;
                }
                else 
                {
                    counter++;
                }
                if(i>1 && nums[i-2]>=nums[i])
                {
                    nums[i]=nums[i-1];
                }
            }
        }
        return true;
    }
};
int main(void)
{
    vector<int>arr={1,2,3};
    Solution ob;
    cout<<ob.canBeIncreasing(arr)<<endl;
}