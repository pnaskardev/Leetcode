#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int maxIceCream(vector<int>& costs, int coins) 
        {
            int counter=0;
            sort(costs.begin(),costs.end());
            for(auto i:costs)
            {
                if(i<=coins)
                {
                    counter++;
                    coins-=i;
                }
                else
                {
                    break;
                }
            }
            return counter;
        }
};
int main(void)
{
    
}