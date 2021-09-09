#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<pair<int,int>>p;
        vector<string>s;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            j=i;
            while(j+1<nums.size() && nums[j+1]==nums[j]+1)
            {
                j++;
            }
            if(i==j)
            {
                s.push_back(to_string(nums[i]));
            }
            else
            {
                s.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
                i=j;
            }
        }
        return s;
    }
};
int main(void)
{
    vector<int>arr={0,1,2,4,5,7};
    vector<int>arr1={0,2,3,4,6,8,9};
    vector<int>arr2={};
    vector<int>arr3={-1};
    vector<int>arr4={0};
    Solution ob;
    auto res=ob.summaryRanges(arr3);
    cout<<"[";
    for(auto i:res)
    {
        cout<<i<<",";
    }
    cout<<"]";
    cout<<endl;
}