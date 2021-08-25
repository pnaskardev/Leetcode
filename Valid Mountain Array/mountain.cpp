#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int i=0,flag=0;
        vector<int>peaks;
        if(arr.size()>=3)
        {
            while (i<arr.size() && arr.size()>1)
            {
                if(i==0)
                {
                    if(arr[i]>arr[i+1]|| arr[i]==arr[i+1])
                    {
                        return false;
                    }
                }
                else if(i>0 && i<=arr.size()-2)
                {
                    if(arr[i]==arr[i+1])
                    {
                        return false;
                    }
                     else if(arr[i]>arr[i-1] && arr[i+1]<arr[i])
                    {
                        flag++;
                    }   
                }
                else if(i==arr.size()-1)
                {
                    if(arr[i-1]<arr[i])
                    {
                        return false;
                    }
                }
                i++;
            }
        }
        else 
        {
            return false;
        }
        if(flag==1)
        {
             return true;
        }
        return false;
    }
};
int32_t main(void)
{
    vector<int>arr1={3,7,6,4,3,0,1,0};
    Solution ob;
    cout<<ob.validMountainArray(arr1)<<endl;
}