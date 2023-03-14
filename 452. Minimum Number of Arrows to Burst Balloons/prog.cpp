#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int findMinArrowShots(vector<vector<int>>& points) 
        {
            sort(points.begin(),points.end());
            int res=1;
            int lp=points[0][1];
            for(auto i:points)
            {
                if(i[0]>lp)
                {
                    res++;
                    lp=i[1];
                }
                lp=min(lp,i[1]);

            }
            return res;
        }
};
int main(void)
{
    vector<vector<int>>arr=
    {
        {10,16},
        {2,8},
        {1,6},
        {7,12}
    };
    Solution ob;
    cout<<ob.findMinArrowShots(arr)<<endl;
}