#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        unordered_map<int,int>mp;
        for(auto i:deck)
        {
            mp[i]++;
        }  

        int gcd=0;

        for(auto i:mp)
        {
            gcd=__gcd(i.second,gcd);
        }

        if(gcd>=2)
        {
            return true;
        }
        return false;
    }
};

int main(void)
{
    vector<int>arr1={1,2,3,4,4,3,2,1};
    vector<int>arr2={1,1,1,2,2,2,3,3};
    Solution obj;
    cout<<obj.hasGroupsSizeX(arr1)<<endl;
}