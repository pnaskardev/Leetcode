#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(mp[nums2[i]]>0)
            {
                mp[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};
int main(void)
{
    vector<int>arr1={1,2,2,1};
    vector<int>arr2={2,2};
    Solution ob;
    auto res=ob.intersect(arr1,arr2);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}