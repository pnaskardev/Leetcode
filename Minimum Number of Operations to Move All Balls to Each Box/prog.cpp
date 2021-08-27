#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        vector<int>ans(boxes.size());
        vector<int>left(boxes.size());
        vector<int>right(boxes.size());
        int box=boxes[0]-'0';
        int prev_step=0;
        for(int i=1;i<boxes.size();i++)
        {
            left[i]=prev_step+box;
            prev_step+=box;
            box+=boxes[i]-'0';
        } 
        prev_step=0;
        box=boxes[boxes.size()-1]-'0';
        for(int i=boxes.size()-2;i>=0;i--)
        {
            right[i]=prev_step+box;
            prev_step+=box;
            box+=boxes[i]-'0';
        }
        for(int i=0;i<ans.size();i++)
        {
            ans[i]=left[i]+right[i];
        }
        return ans;
    }
};
int32_t main(void)
{
    string s="110";
    string s1="001011";
    Solution ob;
    auto res=ob.minOperations(s1);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}