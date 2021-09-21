#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
    int binary(vector<bool>&a)
    {
        int start=0;
        int end=a.size()-1;
        int ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(a[mid]==true)
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        vector<bool>a={false};
        a.resize(arr.size());
        a[0]=true;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>arr[i-1])
            {
                a[i]=true;
            }
            else
            {
                a[i]=false;
            }
        }
        return binary(a);
    }
};
int main(void)
{
    vector<int>arr={3,4,5,1};
    vector<int>arr1={0,10,5,2};
    vector<int>arr2={0,2,1,0};
    vector<int>arr3={0,1,0};
    vector<int>arr4={24,69,100,99,79,78,67,36,26,19};
    Solution ob;
    cout<<ob.peakIndexInMountainArray(arr4)<<endl;
}