#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
        unordered_map<char,char>mp=
        {
            {')','('},
            {'}','{'},
            {']','['}
        };
    public:
        bool isValid(string s) 
        {
            unordered_map<char,char>::iterator it;
            stack<char>st;
            if(s.size()==0)
            {
                return true;
            }
            if(s.size()==1)
            {
                return false;
            }
            bool ans=true;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                {
                    st.push(s[i]);
                }
                else
                {
                    it=mp.find(s[i]);
                    if(!st.empty() && st.top()==it->second)
                    {
                        st.pop();
                    }
                    else
                    {
                        ans=false;
                        return ans;
                        // break;
                    }
                }
            }
            if(st.size()>0)
            {
                ans=false;
            }
            return ans;
        }
};

int main(void)
{
    string s="()[]{}";
    string s1="(]";
    string s2="]";
    Solution obj;
    auto ans=obj.isValid(s2);
    if(ans==true)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}