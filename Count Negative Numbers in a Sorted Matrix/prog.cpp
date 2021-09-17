#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
    int binary(vector<int>arr)
    {
        int start=0,end=arr.size()-1,ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]>=0)
            {
                start=mid+1;
            }
            else
            {
                ans=arr.size()-1-mid+1;
                end=mid-1;
            }
        }
        // for(int i=0;i<arr.size();i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        return ans;
    }

public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int c=0,m=grid.size(),n=grid[0].size();
        //m-> rows,n->columns 
        // cout<<"m->"<<m<<" "<<"n->"<<n<<endl;
        for(int i=0;i<m;i++)
        {
            // cout<<binary(grid[i])<<endl;
            c+=binary(grid[i]);
        }
        return c;
    }
};
int main(void)
{
    vector<vector<int>>arr={{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    vector<vector<int>>arr1={{3,2},{1,0}};
    vector<vector<int>>arr2={{1,-1},{-1,-1}};
    vector<vector<int>>arr3={{5,1,0},{-5,-5,-5}};
    Solution ob;
    cout<<ob.countNegatives(arr3);
    // ob.countNegatives(arr3);
}