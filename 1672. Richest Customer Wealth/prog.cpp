#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int ans=INT_MIN;
        for(int i=0;i<accounts.size();i++)
        {
            int sum=0;
            for(int j=0;j<accounts[i].size();j++)
            {
                sum+=accounts[i][j];
            }
            ans=max(sum,ans);
            sum=0;
        }
        return ans;
    }
};
int main(void)
{
    vector<vector<int>>arr={{1,2,3}
                            ,{3,2,1}
                            };
    Solution ob;
    auto res=ob.maximumWealth(arr);
    cout<<res<<endl;
}