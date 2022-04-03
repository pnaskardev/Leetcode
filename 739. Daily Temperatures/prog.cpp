#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int>ans(temperatures.size(),0);
        stack<pair<int,int>>st;
        int counter=1;
        st.push(make_pair(temperatures[0],0));
        int j=1;
        for(int i=1;i<temperatures.size();i++)
        {   
            if(st.empty())
            {
                st.push(make_pair(temperatures[i],i));
            }
            else
            {
                if(st.top().first<temperatures[i])
                {
                    while(st.top().first<temperatures[i])
                    {
                        ans[st.top().second]=i-st.top().second;
                        st.pop();
                        if(st.empty())
                        {
                            break;
                        }
                    }
                    st.push(make_pair(temperatures[i],i));
                }
                else if(st.top().first>=temperatures[i])
                {
                    st.push(make_pair(temperatures[i],i));
                }
            }
        }
        return ans;
    }
};
int main(void)
{
    vector<int>arr1={73,74,75,71,69,72,76,73};
    vector<int>arr2={30,40,50,60};
    Solution ob;
    auto res=ob.dailyTemperatures(arr1);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}