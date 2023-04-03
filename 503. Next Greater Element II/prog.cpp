#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        vector<int> nextGreaterElements(vector<int>& nums) 
        {
            int n=nums.size();
            stack<int>st;
            vector<int>ans(n,-1);
            for(int i=0;i<2*n;i++)
            {
                while(!st.empty() && nums[i%n]>nums[st.top()%n])
                {
                    ans[st.top()%n]=nums[i%n];
                    st.pop();
                }
                st.push(i%n);
            }
            return ans;
        }
};
int main(void)
{
    // vector<int>arr={1,2,3,4,3};
    vector<int>arr={1,2,1};
    Solution ob;
    auto res=ob.nextGreaterElements(arr);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}