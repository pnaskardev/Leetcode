#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> minOperations(string boxes) 
    {
        vector<int>res(boxes.size(),0);
        vector<int>idx;
        for(int i=0;i<boxes.size();i++)
        {
            if(boxes[i]=='1')
            {
                idx.push_back(i);
            }
        }

        for(int i=0;i<boxes.size();i++)
        {
            for(auto j:idx)
            {
                res[i]+=abs(i-j);
            }
        }

        return res;
    }
};

int main(void)
{
    string s="001011";
    Solution ob;
    auto res=ob.minOperations(s);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}