#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
    bool binary(vector<int>arr,int target)
    {
        int start=0,end=arr.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]==target)
            {
                return true;
            }
            else if(arr[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return false;
    }
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int c=0,i=1;
        while(c!=k)
        {
            if(binary(arr,i)==true)
            {
                i++;
                continue;
            }
            else
            {
                i++;
                c++;
            }
        }
        return i-1;
    }
};
int main(void)
{
    vector<int>arr={2,3,4,7,11};
    vector<int>arr1={1,2,3,4};
    int k=2;
    Solution ob;
    cout<<ob.findKthPositive(arr1,k)<<endl;
}