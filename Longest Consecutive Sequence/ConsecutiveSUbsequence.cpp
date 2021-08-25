#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ln=0;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-1)==mp.end())
            {
                int x=nums[i];
                while(mp.find(x)!=mp.end())
                {
                    x++;
                }
                ln=max(ln,x-nums[i]);
            }
        }
        return ln;
    }
};
int32_t main(void)
{
    vector<int>nums={100,4,200,1,3,2};
    vector<int>nums1={0,3,7,2,5,8,4,6,0,1};
    vector<int>nums2={1, 9, 3, 10, 4, 20, 2};


    vector<int>nums3={-1,-1,-1,-1,-1,-1};
    vector<int>nums4={-1,-1,0,0,-1,-1};
    vector<int>nums5={-1,-1,0,1,1,0};



    Solution ob;
    cout<<ob.longestConsecutive(nums)<<endl;
    cout<<ob.longestConsecutive(nums1)<<endl;
    cout<<ob.longestConsecutive(nums2)<<endl;
    //cout<<ob.pivotIndex(nums3)<<endl;
    //cout<<ob.pivotIndex(nums4)<<endl;
    //cout<<ob.pivotIndex(nums5)<<endl;
}
