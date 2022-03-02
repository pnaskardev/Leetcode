#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        vector<int> getConcatenation(vector<int>& nums) 
        {
            vector<int>ans;
            for(int i=0;i<nums.size();i++)
            {
                ans.push_back(nums[i]);
            }
            for(int i=0;i<nums.size();i++)
            {
                ans.push_back(nums[i]);
            }
            return ans;
        }
};
int main(void)
{
    vector<int>nums={1,2,1};
    Solution ob;
    auto result=ob.getConcatenation(nums);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}