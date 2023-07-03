#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        if(s==goal)
        {
            set<char>temp(s.begin(),s.end());
            return temp.size()<goal.size();
        }
        int n=s.size();
        int i=0,j=n-1;
        while(i<j && s[i]==goal[i])
            i++;
        while(j>=0 && s[j]==goal[j])
            j--;
        if(i<j)
        {
            swap(s[i],s[j]);
        }
        if(s==goal)
            return true;
        return false;
    }
};
int main(void)
{
    string s="ab";
    string goal="ba";

    Solution ob;
    cout<<ob.buddyStrings(s,goal);
}