#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        
    }
};
int main(void)
{
    vector<int>arr={8,1,2,2,3};
    Solution ob;
    auto result=ob.smallerNumbersThanCurrent(arr);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}