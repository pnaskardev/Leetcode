#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        int col=grid.size();
        int rows=grid[0].size();
        vector<int>up;
        vector<int>side;
        int maxm;
        for(int i=0;i<rows;i++)
        {
            maxm=-1;
            for(int j=0;j<col;j++)
            {
                maxm=max(grid[i][j],maxm);
            }
            side.push_back(maxm);
        }
        for(int i=0;i<rows;i++)
        {
            maxm=-1;
            for(int j=0;j<col;j++)
            {
                maxm=max(grid[j][i],maxm);
            }
            up.push_back(maxm);
        }
        int c=0;
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<rows;j++)
            {
                int poss=min(side[i],up[j]);
                if(grid[i][j]<poss)
                {
                    c+=poss-grid[i][j];
                    grid[i][j]=poss;
                }
                else
                {
                    continue;
                }
            }
        }
        return c;
    }     
};
int main(void)
{
    vector<vector<int>>grid={{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    vector<vector<int>>grid1={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    Solution ob;
    cout<<ob.maxIncreaseKeepingSkyline(grid)<<endl;
    // ob.maxIncreaseKeepingSkyline(grid);
}