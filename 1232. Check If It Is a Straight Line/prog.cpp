#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
private:
    double CalculateSlope(vector<int>a, vector<int>b)
    {
        double num=b[1]-a[1];
        double den=b[0]-a[0];

        if(den==0.0)
        {
            return INT_MAX;
        }
        return num/den;
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        double Slope=CalculateSlope(coordinates[0],coordinates[1]);
        bool ans=true;
        for(int i=2;i<coordinates.size();i++)
        {
            if(CalculateSlope(coordinates[i],coordinates[i-1])!=Slope)
            {
                ans=false;
                break;
            }
        }
        return ans;
    }
};
int main(void)
{
    vector<vector<int>>coordinates={{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    vector<vector<int>>coordinates1={{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    Solution ob;
    cout<<ob.checkStraightLine(coordinates)<<endl;

}