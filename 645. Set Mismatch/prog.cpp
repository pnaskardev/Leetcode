#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int>freq(nums.size()+1,0),ans;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        // for(int)
        for(int i=1;i<freq.size();i++)
        {
            if(freq[i]==2)
            {
                ans.push_back(i);
            }
        }
        for(int i=1;i<freq.size();i++)
        {
            if(freq[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(void)
{
    vector<int>arr={1,2,2,4};
    vector<int>arr1={1,1};

    Solution ob;
    auto res=ob.findErrorNums(arr);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}