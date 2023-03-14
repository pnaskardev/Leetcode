#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        int arr[38];
    public:
        // int arr[38];
        int tribonacci(int n) 
        {
            if(n<=1)
            {
                return n;
            }
            if(n==2)
            {
                return 1;
            }
            if(arr[n]!=0)
            {
                return arr[n];
            }
            else 
            {
                arr[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
            }
            return arr[n];
        }
};
int main(void)
{
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.tribonacci(n)<<endl;
}