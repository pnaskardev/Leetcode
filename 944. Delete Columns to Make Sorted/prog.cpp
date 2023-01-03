#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int minDeletionSize(vector<string>& strs) 
        {
            int counter=0;
            bool ans=true;
            int width=strs[0].size();
            for(int j=0;j<width;j++)
            {
                vector<char>temp;
                for(int i=0;i<strs.size();i++)
                {
                    temp.push_back(strs[i][j]);
                }
                if(is_sorted(temp.begin(),temp.end())==false)
                {
                    ans=false;
                    counter++;
                }
            }
            return counter;
        }
};

int main(void)
{
    vector<string> strgs=
    {
        "abc",
        "bce",
        "cae"
    };
    Solution ob;
    cout<<ob.minDeletionSize(strgs)<<endl;
}