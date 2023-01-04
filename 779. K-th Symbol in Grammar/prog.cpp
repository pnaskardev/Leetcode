#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        int solve(int n,int k)
        {
            if(n==1 && k==1)
            {
                return 0;
            }
            int mid=pow(2,n-1)/2;
            if(k<=mid)
            {
                return solve(n-1,k);
            }
            return !solve(n-1,k-mid);
        }
    public:
        int kthGrammar(int n, int k) 
        {
            return solve(n,k);    
        }
};
int main(void)
{
    
}