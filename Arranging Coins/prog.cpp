#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) 
    {
        int start=0,end=n;
        while(start<=end)
        {
            int64_t mid=(end+start)/2;
            int64_t avail=mid*(mid+1)/2;
            if(avail==(int64_t)n)
            {
                return mid;
            }
            else if(avail<n)
            {
                start=mid+1;
            }
            else if(n<avail)
            {
                end=mid-1;
            }
        }
        return end;
    }
};
int main(void)
{
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.arrangeCoins(n);   
}