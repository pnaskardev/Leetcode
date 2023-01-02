#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        bool allCapital(string arr)
        {
            bool ans=true;
            for(auto i:arr)
            {
                if(!isupper(i))
                {
                    ans=false;
                    break;
                }
            }
            return ans;
        }
        bool allSmall(string arr)
        {
            bool ans=true;
            for(auto i:arr)
            {
                if(!islower(i))
                {
                    ans=false;
                    break;
                }
            }
            return ans;
        }
        bool firstCapital(string arr)
        {
            bool ans=true;
            for(int i=0;i<arr.size();i++)
            {
                if(i==0 && !isupper(arr[i]))
                {
                    ans=false;
                }
                else if(i>0 && !islower(arr[i]))
                {
                    ans=false;
                }
            }
            return ans;
        }
    public:
        bool detectCapitalUse(string word) 
        {
            vector<int>arr;
            bool ans=false;
            if(allCapital(word)==true)
            {
                return true;
            }
            else if(allSmall(word)==true)
            {
                return true;
            }
            else if(firstCapital(word)==true)
            {
                return true;
            }
            return ans;
        }
};
int main(void)
{
    string word;
    cin>>word;
    Solution ob;
    cout<<ob.detectCapitalUse(word)<<endl;
}