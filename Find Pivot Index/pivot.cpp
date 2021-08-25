#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        int sum1=0;
        int sum2=0;
        int ans=-1;
        float finalsum=0;
        for(auto i:nums)
        {
            finalsum=finalsum+i;
        }
        //cout<<"FInalsum->"<<finalsum<<endl;
        for(int i=0;i<nums.size();i++)
        {
            float temp=finalsum;
            if(i==0)
            {
                sum1=sum1+nums[i];
                float compare1=sum1-nums[i];
                temp=temp-nums[i];
                temp=temp/2.0;
                //cout<<"compare1->"<<compare1<<" temp->"<<temp<<endl;
                if(compare1==temp)
                {
                    ans=i;
                    return ans;
                }
            }
            if(i==nums.size()-1)
            {
                sum1=sum1+nums[i];
                float compare1=sum1-nums[i];
                temp=temp-nums[i];
                temp=temp/2.0;
                //cout<<"compare1->"<<compare1<<" temp->"<<temp<<endl;
                if(compare1==temp)
                {
                    ans=i;
                    return ans;
                }
            }
            if(i>0 && i<nums.size()-1) 
            {
                sum1=sum1+nums[i];
                int compare1=sum1-nums[i];
                temp=temp-nums[i];
                temp=temp/2.0;
                //cout<<"compare1->"<<compare1<<" temp->"<<temp<<endl;
                if(compare1==temp)
                {
                    ans=i;
                    return ans;
                }
            }
        }
        return ans;
    }
};
int32_t main(void)
{
    vector<int>nums={1,7,3,6,5,6};
    vector<int>nums1={2,1,-1};
    vector<int>nums2={1,2,3};
    vector<int>nums3={-1,-1,-1,-1,-1,-1};
    vector<int>nums4={-1,-1,0,0,-1,-1};
    vector<int>nums5={-1,-1,0,1,1,0};
    Solution ob;
    cout<<ob.pivotIndex(nums)<<endl;
    cout<<ob.pivotIndex(nums1)<<endl;
    cout<<ob.pivotIndex(nums2)<<endl;
    cout<<ob.pivotIndex(nums3)<<endl;
    cout<<ob.pivotIndex(nums4)<<endl;
    cout<<ob.pivotIndex(nums5)<<endl;
}
