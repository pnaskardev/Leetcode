#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        vector<vector<int>>ans;
        vector<int>temp;
        void combine(int index,vector<int>&candidates,int target)
        {
            if(target==0)
            {
                ans.push_back(temp);
                return;
            }
            if(target<0)
            {
                return;
            }
            if(index==candidates.size())
            {
                return;
            }
            // i chose not to pick the first element
            combine(index+1,candidates,target);
            // I chose to pick the first element and moved on
            temp.push_back(candidates[index]);
            // we decided to pick the current element 
            // but we didnt moved on cause we are gonna pick this one again
            combine(index,candidates,target-candidates[index]); 
            temp.pop_back();
        }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
            combine(0,candidates,target);
            return ans;
        }
};
int main(void)
{
    vector<int>arr={2,3,6,7};
    int target=7;
    Solution ob;
    auto res=ob.combinationSum(arr,target);
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