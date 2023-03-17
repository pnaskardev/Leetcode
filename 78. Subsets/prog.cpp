#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        set<vector<int>>ans;
        vector<int> temp;
        void place(int index,vector<int>&nums, set<vector<int>>&ans)
        {
            if(index==nums.size())
            {
                ans.insert(temp);
                return;
            }
            place(index+1,nums,ans);
            temp.push_back(nums[index]);
            place(index+1,nums,ans);
            temp.pop_back();
            place(index+1,nums,ans);
        }
    public:
        vector<vector<int>> subsets(vector<int>& nums) 
        {
            place(0,nums,ans);
            return vector(ans.begin(),ans.end());
        }
};
int main(void)
{
    // vector<int>arr={1,2,3};
    vector<int>arr={0};
    Solution ob;
    auto res=ob.subsets(arr);
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