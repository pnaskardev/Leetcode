#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        set<vector<int>>ans;
        vector<int>temp;
        // stores if the position is vacant or not
        vector<int>present;
        void place(vector<int>&nums,int index)
        {
            if(index>=nums.size())
            {
                ans.insert(temp);
                return;
            }
            for(int i=0;i<nums.size();i++)
            {
                if(present[i]==0)
                {
                    temp.push_back(nums[i]);
                    present[i]=1;
                    place(nums,index+1);
                    temp.pop_back();
                    present[i]=0;
                }
            }
        }
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) 
        {
            for(int i=0;i<nums.size();i++)
            {
                present.push_back(0);
            }
            sort(nums.begin(),nums.end());
            place(nums,0);
            return vector(ans.begin(),ans.end());
        }
};
int main(void)
{
    vector<int>arr={1,1,2};
    Solution ob;
    auto res=ob.permuteUnique(arr);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}