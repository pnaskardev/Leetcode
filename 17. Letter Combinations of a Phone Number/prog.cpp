#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        vector<string> pad = 
        {
            "", 
            "", 
            "abc", 
            "def", 
            "ghi", 
            "jkl", 
            "mno", 
            "pqrs", 
            "tuv", 
            "wxyz"
        };
        vector<string>ans;
        string temp;
        void place(int index,string digits)
        {
            if(index==digits.size())
            {
                ans.push_back(temp);
                return;
            }
            if(index>digits.size())
            {
                return;
            }
            // stores the string related to the number
            string value=pad[digits[index]-'0'];
            for(int i=0;i<value.size();i++)
            {
                temp.push_back(value[i]);
                place(index+1,digits);
                temp.pop_back();
            }
        }
    public:
        vector<string> letterCombinations(string digits) 
        {
            if(digits.size()==0)
            {
                return {};
            }
            place(0,digits);
            return ans;
        }
};
int main(void)
{
    Solution ob;
    auto res=ob.letterCombinations("23");
    for(auto i:res)
    {
        cout<<i<<endl;
    }
}