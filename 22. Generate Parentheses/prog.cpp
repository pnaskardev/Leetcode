#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        bool valid(vector<char> temp)
        {
            int balance=0;
            for(auto i:temp)
            {
                if(i=='(')
                {
                    balance++;
                }
                else if(i==')')
                {
                    balance--;
                }
                if(balance<0)
                {
                    return false;
                }
            }
            if(balance==0)
            {
                return true;
            }
            return false;
        }
        void generate(vector<string>&combinations,vector<char> &temp,int position)
        {
            if(position==temp.size())
            {
                // if its valid push it into the combinations
                if(valid(temp))
                {
                    combinations.push_back(string(temp.begin(),temp.end()));
                }  
                return;  
            }
            temp[position]='(';
            generate(combinations,temp,position+1);
            temp[position]=')';
            generate(combinations,temp,position+1);
        }
    public:
        vector<string> generateParenthesis(int n) 
        {
            vector<char> temp(2*n);
            vector<string> combinations;
            generate(combinations,temp,0);
            return combinations;
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
        cout<<i<<endl;
    }
}