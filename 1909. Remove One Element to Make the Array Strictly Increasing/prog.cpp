#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        int LeftCounter=0,RightCounter=0,LastElement=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>LastElement)
            {
                LastElement=nums[i];
            }
            else
            {
                // LastElement=nums[i];
                LeftCounter++;
            }
        }
        LastElement=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<LastElement)
            {
                LastElement=nums[i];
            }
            else
            {
                RightCounter++;
                // LastElement=nums[i];
            }
        }
        // cout<<LeftCounter<<" "<<RightCounter<<endl;
        if(min(LeftCounter,RightCounter)<=1)
        {
            
            return true;
        }
        return false;
    }
};
int main(void)
{
    vector<int>arr={1,2,10,5,7};
    vector<int>arr1={2,3,1,2};
    vector<int>arr2={1,1,1};

    Solution ob;
    if(ob.canBeIncreasing(arr))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}