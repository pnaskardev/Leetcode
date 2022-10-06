#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        vector<vector<int>>ans;
        void solve(int pos,vector<int>&candidates,vector<int>&temp,int target)
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
            if(pos==candidates.size())
            {
                return;
            }
            // we decided that we are not taking the current element
            solve(pos+1,candidates,temp,target);

            // we decided that we are taking the current element 
            // if we are taking the current element that means
            // we need to subtract the current element from the target
            // therefore we need to decrease the sum and need to call the function again
            // to backtrack for the remaining target 
            temp.push_back(candidates[pos]);
            solve(pos,candidates,temp,target-candidates[pos]);
            temp.pop_back();

        }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
            ans.clear();
            vector<int>temp;
            solve(0,candidates,temp,target);
            return ans;
        }
};

int main(void)
{
    vector<int>arr={2,3,6,7};
    int target=7;
    Solution ob;
    auto res=ob.combinationSum(arr,7);
    
}