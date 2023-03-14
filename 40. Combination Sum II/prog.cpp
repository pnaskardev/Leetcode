#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        set<vector<int>>ans;
        void solve(int pos,vector<int>&candidates,vector<int>&temp,int target)
        {
            if(target==0)
            {
                ans.insert(temp);
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
            // we decided that we are taking the current element 
            // if we are taking the current element that means
            // we need to subtract the current element from the target
            // therefore we need to decrease the sum and need to call the function again
            // to backtrack for the remaining target 
            temp.push_back(candidates[pos]);
            solve(pos+1,candidates,temp,target-candidates[pos]);
            temp.pop_back();
            // since one element can be repeated we need to find the last occurence of the element 
            // that is being repeated
            while(pos<candidates.size()-1 && candidates[pos]==candidates[pos+1])
            {
                pos++;
            }
            // we decided that we are not taking the current element
            solve(pos+1,candidates,temp,target);
        }
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
        {
            ans.clear();
            vector<int>temp;
            sort(candidates.begin(),candidates.end());
            solve(0,candidates,temp,target);
            return vector<vector<int>>(ans.begin(),ans.end());
        }
};

int main(void)
{
    vector<int>arr={10,1,2,7,6,1,5};
    int target=8;
    Solution ob;
    auto res=ob.combinationSum2(arr,target);
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