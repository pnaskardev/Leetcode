#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        vector<vector<int>>ans;
        void combine(int index,int target,vector<int>&candidates,vector<int>&temp)
        {
            if(index==candidates.size())
            {
                return;
            }
            if(target<0)
            {
                return;
            }
            if(target==0)
            {
                ans.push_back(temp);
                return;
            }
            combine(index+1,target,candidates,temp);
            temp.push_back(candidates[index]);
            combine(index,target-candidates[index],candidates,temp);
            temp.pop_back();
        }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
            ans.clear();
            vector<int>temp;
            combine(0,target,candidates,temp);
            return ans;
        }
};
int main(void)
{
    vector<int>arr={2,3,6,7};
    int target=7;
    Solution ob;
    auto res=ob.combinationSum(arr,target);
    cout<<res.size()<<endl;
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