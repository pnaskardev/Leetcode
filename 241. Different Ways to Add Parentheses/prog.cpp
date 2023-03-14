#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        vector<int> diffWaysToCompute(string expression) 
        {
            vector<int>res;
            bool onlyNumber=true;
            for(int i=0;i<expression.size();i++)
            {
                if(!isdigit(expression[i]))
                {
                    // expression doesnt only has a number
                    // if onlyNumber is true that means there are 
                    // no operators in the String 
                    onlyNumber=false;
                    // cout<<"!isdigit"<<endl;
                    char c=expression[i];
                    if(c=='+'||c=='*'||c=='-')
                    {
                        vector<int> left=diffWaysToCompute(expression.substr(0,i));
                        vector<int> right=diffWaysToCompute(expression.substr(i+1));
                        for(int x:left)
                        {
                            for(int y:right)
                            {
                                if(c == '+') res.push_back(x+y);
                                if(c == '-') res.push_back(x-y) ;
                                if(c == '*') res.push_back(x * y);
                            }
                        }
                    }
                    
                }
            }
            if(onlyNumber==true)
            {   
                res.push_back(stoi(expression));
            }
            return res;
        }
};
int main(void)
{
    string test="2-1-1";
    // string test="11";
    Solution obj;
    auto res=obj.diffWaysToCompute(test);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}