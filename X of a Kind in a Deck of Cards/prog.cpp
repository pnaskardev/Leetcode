#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        unordered_map<int,int>mp;
        vector<int>arr;
        for(int i=0;i<deck.size();i++)
        {
            mp[deck[i]]++;
        }
        int g=mp[deck[0]];
        for(auto i:mp)
        {
            cout<<i.first<<" "<<i.second<<endl;
            if(i.second<2)
            {
                return false;
            }
            else
            {
                g=__gcd(i.second,g);
                cout<<"gcd->"<<g<<endl;
            }
        }
        if(g>=2)
        {
            return true;
        }
        return false;
    }
};
int32_t main(void)
{
    vector<int>arr1={1,2,3,4,4,3,2,1};  
    vector<int>arr2={1,1,1,2,2,2,3,3};    
    vector<int>arr3={1};
    vector<int>arr4={1,1};
    vector<int>arr5={1,1,2,2,2,2};
    Solution ob;
    cout<<ob.hasGroupsSizeX(arr5)<<endl;
}