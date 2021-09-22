#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
    int binary(vector<int>&numbers,int comp,int idx)
    {
        int start=0,end=numbers.size()-1,ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(numbers[mid]==comp)
            {
                return mid;
            }
            else if(numbers[mid]>comp)
            {
                end=mid-1;
            }
            else if(numbers[mid]<comp)
            {
                start=mid+1;
            }
        }
        return ans;

    }
    public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int>res;
        sort(numbers.begin(),numbers.end());
        for(int i=0;i<numbers.size();i++)
        {
            int comp=target-numbers[i];
            int idx=binary(numbers,comp,i);
            if(numbers[i]+numbers[idx]==target && i==idx )
            {
                if(numbers[i+1]==comp)
                    res.push_back(i+1);
                    res.push_back(idx+2);
                // cout<<"number[i]->"<<numbers[i]<<" comp-> "<<comp<<" idx-> "<<idx<<" numbers[idx]->"<<numbers[idx]<<" "<<"i->"<<i<<endl;
                break;
            }
            if(numbers[i]+numbers[idx]==target && i!=idx)
            {
                res.push_back(i+1);
                res.push_back(idx+1);
                // cout<<"number[i]->"<<numbers[i]<<" comp-> "<<comp<<" idx-> "<<idx<<" numbers[idx]->"<<numbers[idx]<<" "<<"i->"<<i<<endl;
                break;
            }
        }
        return res;
    }
};
int main(void)
{
    vector<int>arr={2,7,11,15};
    vector<int>arr1={2,3,4};
    vector<int>arr2={-1,0};
    vector<int>arr3={1,2,3,4,4,9,56,90};
    int target=8;
    Solution ob;
    ob.twoSum(arr3,target);
}