#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>>arr;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            arr.push_back(make_pair(i->second,i->first));
        }
        sort(arr.rbegin(),arr.rend());
        // for(auto i:arr)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        string ans;
        for(auto i:arr)
        {
            int t=i.first;
            while(t--)
            {
                ans.push_back(i.second);
            }
        }
        // cout<<ans<<endl; 
        return ans;
    }
};
int main(void)
{
    string s;
    cin>>s;
    Solution ob;
    cout<<ob.frequencySort(s)<<endl;
}