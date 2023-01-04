#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        unordered_map<int,int>mp;
    public:
        int minimumRounds(vector<int>& tasks) 
        {
            int ans=0;
            for(auto i:tasks)
            {
                mp[i]++;
            }
            for(auto i:mp)
            {
                if(i.second==1)
                {   
                    ans=-1;
                    break;
                }
                else if(i.second%3==0)
                {
                    ans+=i.second/3;
                }
                else 
                {
                    ans+=i.second/3+1;
                }
            }
            return ans;
        }
};
int main(void)
{
    vector<int>arr={2,2,3,3,2,4,4,4,4,4};
    vector<int>arr1={2,3,3};
    Solution ob;
    cout<<ob.minimumRounds(arr1)<<endl;
}