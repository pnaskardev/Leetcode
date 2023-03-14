#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
        {
            int total_gas=0,total_cost=0,curr_gas=0,starting_point=0;
            for(int i=0;i<gas.size();i++)
            {
                total_gas+=gas[i];
                total_cost+=cost[i];
                curr_gas+=gas[i]-cost[i];
                if(curr_gas<0)
                {
                    curr_gas=0;
                    starting_point=i+1;
                }
            }
            if(total_gas<total_cost)
            {
                return -1;
            }
            return starting_point;
        }
};
int main(void)
{
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};
    Solution ob;
    cout<<ob.canCompleteCircuit(gas,cost)<<endl;
}