#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
        vector<vector<int>>ans;

        void backtrack(int n,int k,int start,vector<int>&temp)
        {
            if(temp.size()==k)
            {
                ans.push_back(temp);
                return;
            }
            for(int i=start;i<=n;i++)
            {
                temp.push_back(i);
                backtrack(n,k,i+1,temp);
                temp.pop_back();
            }
        }

    public:
        vector<vector<int>> combine(int n, int k) {
            vector<int>temp;
            backtrack(n,k,1,temp);
            return ans;    
        }
};

int main(void)
{
    int n,k;
    n=4,k=2;
    Solution ob;
    vector<vector<int>>ans=ob.combine(n,k);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}