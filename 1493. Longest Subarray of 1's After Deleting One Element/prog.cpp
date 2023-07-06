#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int ans=0;
        int count=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==0)
                count++;
            while(count>1)
            {
                if(nums[i]==0)
                    count--;
                i++;
            }
            ans=max(ans,j-i+1-count);
        }
        if(ans==nums.size())
            return ans-1;
        return ans;
    }
};

int main(void)
{
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    Solution obj;
    cout<<obj.longestSubarray(nums);
}