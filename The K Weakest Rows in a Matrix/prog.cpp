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
        return ans;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        
    }
};
int main(void)
{
    
}