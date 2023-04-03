#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        vector<vector<int>>presum;
        int solve(vector<vector<int>>&ans,int row1, int col1, int row2, int col2) 
        {
            int sum=0;
            sum+=presum[row2][col2];
            if(col1>0) sum-=presum[row2][col1-1];
            if(row1>0) sum-=presum[row1-1][col2];
            if(col1>0 && row1>0) sum+=presum[row1-1][col1-1];
            return sum;
        }
    public:
        vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
        {
            int m=mat.size(),n=mat[0].size();
            // row wise sum
            for(int i=0;i<mat.size();i++)
            {
                for(int j=1;j<mat[i].size();j++)
                {
                    mat[i][j]=mat[i][j]+mat[i][j-1];
                }
            }
            // column wise sum
            for(int i=1;i<mat.size();i++)
            {
                for(int j=0;j<mat[i].size();j++)
                {
                    mat[i][j]=mat[i][j]+mat[i-1][j];
                }
            }
            presum=mat;
            vector<vector<int>>ans(m,vector<int>(n,0));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    ans[i][j]=solve(ans,(i<k)?0:i-k,(j<k)?0:j-k,(i+k)>=m?m-1:i+k,(j+k)>=n?n-1:j+k);
                }
            }
            return ans;
        }
};
int main(void)
{
    int k=1;
    vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};
    Solution ob;
    auto res=ob.matrixBlockSum(arr,k);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}