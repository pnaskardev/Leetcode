#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool wordPattern(string pattern, string s) 
        {
            unordered_map<char,string> mp;
            unordered_map<char,string>::iterator it;
            int n=s.size();
            vector<string> vec;
            stringstream ss(s);
            string word;
            while(ss>>word)
            {
                vec.push_back(word);
            }
            if(vec.size()!=pattern.size())
            {
                return false;
            }
            bool ans=true;
            set<string>st;
            for(int i=0;i<pattern.size();i++)
            {
                if(mp.find(pattern[i])!=mp.end())
                {
                    it=mp.find(pattern[i]);
                    if(it->second != vec[i])
                    {
                        ans=false;
                        break;
                    }
                }
                else
                {
                    if(st.count(vec[i])>0)
                    {
                        ans=false;
                        break;
                    }
                    else
                    {
                        mp[pattern[i]]=vec[i];
                        st.insert(vec[i]);
                    }
                }
            }
            // cout<<ans<<endl;  
            return ans;     
        }
};

int main(void)
{
    string p="abba",
    s="dog cat cat dog";
    Solution ob;
    cout<<ob.wordPattern(p,s)<<endl;
}