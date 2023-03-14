#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int ans=1;
        for(int i=0;i<points.size()-1;i++)
        {
            map<double,int> mp;
            for(int j=i+1;j<points.size();j++)
            {
                
                double slope=(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                if((points[j][1]-points[i][1])<0 && (points[j][0]-points[i][0])==0)
                {
                    mp[abs(slope)]++;
                }
                else
                {
                    mp[slope]++;
                }
            }
            int temp=0;
            for(auto i:mp)
            {
                temp=max(temp,i.second+1);
            }
            ans=max(temp,ans);
        }
        return ans;
    }
};
int main(void)
{
    vector<vector<int>>points={{1,1},{2,2},{3,3}};
    Solution ob;
    cout<<ob.maxPoints(points);
}