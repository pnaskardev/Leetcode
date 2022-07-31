#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int i=0;
        bool ans=true;
        if(arr.size()<3)
        {
            return false;
        }
        for(i;i<arr.size()-1;i++)
        {
            if(arr[i+1]<arr[i])
            {
                i++;
                break;
            }
            else if(arr[i]==arr[i+1])
            {
                ans=false;
                // return false;
            }
        }
        if(i<2)
        {
            // return false;
            ans=false;
        }
        for(;i<arr.size();i++)
        {
            if(arr[i]>=arr[i-1])
            {
                // return false;
                ans=false;
            }
        }
        // return true;
        return ans;
    }
};
int main(void)
{
    Solution ob;
    vector<int>arr={0,3,2,1};
    vector<int>arr1={3,5,5};
    vector<int>arr2={2,1};
    cout<<ob.validMountainArray(arr1)<<endl;
}