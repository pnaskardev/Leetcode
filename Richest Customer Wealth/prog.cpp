#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int maximumWealth(vector<vector<int>>& accounts) 
        {
            int ans=INT_MIN;
            int r=accounts.size();
            int c=accounts[0].size();
            for(int i=0;i<r;i++)
            {
                int sum=0;
                for(int j=0;j<c;j++)
                {
                    sum+=accounts[i][j];
                }
                ans=max(sum,ans);
            }
            return ans;
        }
};
int main(void)
{
    vector<vector<int>>arr={{1,2,3},{3,2,1}};
    Solution ob;
    auto result=ob.maximumWealth(arr);
    cout<<result<<endl;
}