#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        vector<int> buildArray(vector<int>& nums) 
        {
            int n=nums.size();
            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                ans.push_back(nums[nums[i]]);
            }
            return ans;
        }
};
int main(void)
{
    vector<int>arr={0,2,1,5,3,4};
    Solution ob;
    auto result=ob.buildArray(arr);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}