#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MAXN=5e6;
bool prime[MAXN];
void fill_primes()
{
        memset(prime,true,sizeof(prime));
        prime[1]=false;
        for(int i=2;i<MAXN;i++)
        {
            if(prime[i]==true)
            {
                for(int j=i*i;j<MAXN;j+=i)
                {
                    prime[j]=false;
                }
            }
            if(i*i>MAXN)
            {
                break;
            }
        }
}
class Solution {
public:  
    int countPrimes(int n) 
    {
        fill_primes();
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(prime[i]==true)
            {
                count++;
            }
        }
        return count;
    }
};
int32_t main(void)
{
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.countPrimes(n)<<endl;
}