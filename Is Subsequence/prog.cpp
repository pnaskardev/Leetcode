#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        bool isSubsequence(string s, string t) 
        {
            int n=t.size();
            int count=0;
            int i=0,j=0;
            while(j<n)
            {
                if(s[i]==t[j])
                {
                    i++;
                    count++;
                }
                j++;
            }
            if(count==s.size())
            {
                return true;
            }
            return false;
        }
};
int main(void)
{
    string s = "acb", t = "ahbgdc";
    Solution ob;
    cout<<ob.isSubsequence(s,t)<<endl;
}
