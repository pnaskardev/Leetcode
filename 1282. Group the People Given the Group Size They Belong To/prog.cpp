#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        vector<vector<int>>arr;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<groupSizes.size();i++)
        {
            mp[groupSizes[i]].push_back(i);
            if(mp[groupSizes[i]].size()==groupSizes[i])
            {
                arr.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
            }

        }
        return arr;
    }
};

int main(void)
{
    
}