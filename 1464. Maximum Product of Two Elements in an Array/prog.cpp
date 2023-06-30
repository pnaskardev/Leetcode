#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int maxProduct(vector<int>& nums) 
        {
            priority_queue<int>pq;
            for(auto i:nums)
                pq.push(i);
            
            int x,y;
            x=pq.top();
            pq.pop();

            y=pq.top();
            pq.pop();

            return (x-1)*(y-1);
        }
};
int main(void)
{
    vector<int>arr={3,4,5,2};
    Solution ob;
    cout<<ob.maxProduct(arr)<<endl;

}