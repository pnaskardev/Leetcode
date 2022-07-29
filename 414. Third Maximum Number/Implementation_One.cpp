#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int thirdMax(vector<int>& nums)
    {
        unordered_map<int,int>mp;
        vector<int>temp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            temp.push_back(i.first);
        }
        sort(temp.begin(),temp.end());
        if(temp.size()>=3)
        {
            return temp[temp.size()-3];
        }

        return temp[temp.size()-1];

    }
};
int main(void)
{
    Solution ob;
    vector<int>arr={3,2,1};
    vector<int>arr1={2,1};
    vector<int>arr2={2,2,3,1};
    vector<int>arr3={1,2};

    cout<<ob.thirdMax(arr3)<<endl;
}