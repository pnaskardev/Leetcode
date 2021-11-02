#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int res=0,empty=1;
    void dfs(vector<vector<int>>& grid, int x, int y, int count)
    {
        if(x<0||x>=grid.size()|| y>=grid[0].size()||y<0||grid[x][y]==-1)
        {
            return;
        }
        if(grid[x][y]==2)
        {
            if(empty==count)
            {
                res++;
            }
            return;
        }
        grid[x][y]=-1;
        dfs(grid,x+1,y,count+1);
        dfs(grid,x-1,y,count+1);
        dfs(grid,x,y+1,count+1);
        dfs(grid,x,y-1,count+1);
        grid[x][y]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int x,y;
        int col=grid[0].size();
        int row=grid.size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
                else if(grid[i][j]==0)
                {
                    empty++;
                }
            }
        }
        dfs(grid,x,y,0);
        return res;
    }
};

int main(void)
{
    vector<vector<int>>arr;
    Solution ob;
    cout<<ob.uniquePathsIII(arr);
}