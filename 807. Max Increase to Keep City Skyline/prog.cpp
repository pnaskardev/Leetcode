#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        vector<int>row(grid.size(),0),column(grid.size(),0);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                row[i]=max(row[i],grid[i][j]);
                column[i]=max(grid[j][i],column[i]);
            }
        }
        int ans=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                // row[i]=max(row[i],grid[i][j]);
                // column[i]=max(grid[j][i],column[i]);
                ans+=min(row[i],column[j])-grid[i][j];
            }
        }

        return ans;

    }   
};

int main(void)
{
    vector<vector<int>>arr=
    {
        {3,0,8,4},
        {2,4,5,7},
        {9,2,6,3},
        {0,3,1,0}
    };

    Solution ob;
    cout<<ob.maxIncreaseKeepingSkyline(arr)<<endl;
}