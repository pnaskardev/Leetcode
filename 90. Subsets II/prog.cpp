#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        set<vector<int>> ans;
        vector<int> temp;
        void place(int index,vector<int>&nums)
        {
            if(index==nums.size())
            {
                ans.insert(temp);
                return;
            }
            // we decided to not pick the element 
            place(index+1,nums);
            // we decided to pick the current element
            temp.push_back(nums[index]);
            place(index+1,nums);
            temp.pop_back();
        }
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) 
        {
            sort(nums.begin(),nums.end());
            place(0,nums);
            return vector(ans.begin(),ans.end());
        }
};
int main(void)
{
    vector<int>arr={4,4,4,1,4};
    Solution ob;
    auto res=ob.subsetsWithDup(arr);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}