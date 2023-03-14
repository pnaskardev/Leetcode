#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{  
    public:
        int myAtoi(string s) 
        {
            double num=0.0;
            int index=0;
            while(s[index]==' ')
            {
                index++;
            }        
            bool isPositive=s[index]=='+';
            bool isNegetive=s[index]=='-';
            isPositive==true?index++:index;
            isNegetive==true?index++:index;
            string temp;
            while(index<s.size() && s[index]>='0' && s[index]<='9')
            {
                num=num*10+(s[index]-'0');
                index++;
            }
            num=isNegetive?-num:num;
            num = (num > INT_MAX) ? INT_MAX : num;
            num = (num < INT_MIN) ? INT_MIN : num;
            // cout<<num<<endl;
            return int(num);
        }
};
int main(void)
{
    string s="4193 with words";
    Solution ob;
    cout<<ob.myAtoi(s)<<endl;
}