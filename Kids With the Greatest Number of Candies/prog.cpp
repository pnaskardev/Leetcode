#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxim=INT_MIN;
        for(auto i:candies)
        {
            maxim=max(i,maxim);
        }
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=maxim)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};

int main(void)
{
    int extra;
    vector<int>candies={2,3,5,1,3};
    Solution ob;
    auto result=ob.kidsWithCandies(candies,3);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}