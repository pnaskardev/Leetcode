#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int power(int a,int b)
    // {   
    //     int ans=1;
    //     while(b>0)
    //     {   
    //         if(b%2==1)
    //         {
    //             ans=ans*a;
    //         }
    //         b=b>>1;
    //         a=a*a;
    //     }
    //     return ans;
    // }
    int mySqrt(int x) 
    {
        if(x==0)
        {
            return 0;
        }
        int start=1,end=1e3,ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(pow(mid,2)<=x)
            {
                ans=mid;
                start=mid+1;
                // cout<<mid<<"->"<<pow(mid,2)<<endl;
            }
            else
            {
                end=mid-1;
                // cout<<mid<<"->"<<pow(mid,2)<<endl;
            }
        }
        return ans;
    }
};
int main(void)
{
    Solution ob;
    int x=8;
    cout<<ob.mySqrt(x)<<endl;
}
