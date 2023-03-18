#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        vector<vector<int>>ans;
        vector<int>temp;
        void place(int index,int k,int target)
        {
            if(index>10)
            {
                return;
            }
            if(k<0)
            {
                return;
            }
            if(target==0 && k==0)
            {
                ans.push_back(temp);
                return;
            }
            // // cout<<index<<" "<<target<<endl;
            // for(auto i:temp)
            // {
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            // I chose not to pick the current element
            place(index+1,k,target);
            // I chose to pick the current element
            temp.push_back(index);
            place(index+1,k-1,target-index);
            temp.pop_back();
        }
    public:
        vector<vector<int>> combinationSum3(int k, int n) 
        {
            place(1,k,n);
            return ans;
        }
};
int main(void)
{
    Solution ob;
    auto res=ob.combinationSum3(9,45);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}