#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int counter=0;
        vector<int>ans;
        for(int i=0;i<sentences.size();i++)
        {
            string s=sentences[i];
            for(int j=0;j<s.size();j++)
            {
                if(s[j]==' ')
                {
                    counter++;
                }
            }
            ans.push_back(counter+1);
            counter=0;
        }
        int p=INT_MIN;
        for(auto i:ans)
        {
            p=max(p,i);
        }
        // cout<<p<<endl;
        return p;
    }
};
int main(void)
{
    vector<string>sentences={"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    vector<string>sentences1={"please wait", "continue to fight", "continue to win"};
    Solution ob;
    cout<<ob.mostWordsFound(sentences1)<<endl;
}