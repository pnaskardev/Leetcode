//BRUTE FORCE SOLUTION
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        vector<int>res;
        for(int i=0;i<queries.size();i++)
        {
            int c=0;
            int x=queries[i][0],y=queries[i][1],r=queries[i][2];
            for(int j=0;j<points.size();j++)
            {
                if(pow(r,2)>=pow(x-points[j][0],2)+pow(y-points[j][1],2))
                {
                    c++;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};
int main(void)
{
    vector<vector<int>> points={{1,3},{3,3},{5,3},{2,2}};
    vector<vector<int>> queries={{2,3,1},{4,3,1},{1,1,2}};
    Solution ob;
    auto res=ob.countPoints(points,queries);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}