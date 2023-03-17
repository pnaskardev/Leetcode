#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
       
        bool checkValid(vector<char> temp)
        {
            int counter=0;
            for(auto i:temp)
            {
                if(i=='(')
                {
                    counter++;
                }
                else if(i==')')
                {
                    counter--;
                }
                if(counter<0)
                {
                    return false;
                }
            }
            if(counter==0)
            {
                return true;
            }
            return false;
        }
        void place(int index,vector<string>&ans, vector<char> &temp)
        {
            if(index==temp.size())
            {
                if(checkValid(temp))
                {
                    ans.push_back(string(temp.begin(),temp.end()));
                }
                return;
            }
            temp[index]='(';
            place(index+1,ans,temp);
            temp[index]=')';
            place(index+1,ans,temp);
        }
    public:
        vector<string> generateParenthesis(int n) 
        {
            vector<string>ans;
            vector<char>temp(2*n);
            place(0,ans,temp);
            return ans;
        }
};
int main(void)
{
    int n;
    cin>>n;
    Solution ob;
    auto res=ob.generateParenthesis(n);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}