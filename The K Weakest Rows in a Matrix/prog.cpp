#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
    int binary(vector<int>arr)
    {
        int start=0,end=arr.size()-1,sold_idx=0,zeroes=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]==0)
            {
                end=mid-1;
            }
            if(arr[mid]==1)
            {
                sold_idx=mid+1;
                start=mid+1;
            }
        }
        return sold_idx;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<pair<int,int>>res;
        vector<int>resfinal;
        int c=0,m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            res.push_back(make_pair(binary(mat[i]),i));
        }
        // for(auto i:res)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        //     // cout<<i<<" ";
        // }
        sort(res.begin(),res.end());
        for(int i=0;i<k;i++)
        {
            resfinal.push_back(res[i].second);
        }
        
        // cout<<endl;
        return resfinal;
    }
};
int main(void)
{
    int k;
    vector<vector<int>>mat={{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    vector<vector<int>>mat1={{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}};
    vector<vector<int>>mat2={{1,0},{0,0},{1,0}};
    k=3;
    Solution ob;
    auto res=ob.kWeakestRows(mat2,2);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}