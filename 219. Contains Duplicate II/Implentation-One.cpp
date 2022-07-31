#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        vector<pair<int,int>>arr(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            arr[i].first=nums[i];
            arr[i].second=i;
        }    
        bool ans=false;
        sort(arr.begin(),arr.end());

        // for(auto i:arr)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }

        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i].first==arr[i+1].first)
            {
                if((abs(arr[i].second-arr[i+1].second))<=k)
                {
                    ans=true;
                    break;
                }
            }
        }
        return ans;
    }
};
int main(void)
{
    vector<int>arr={1,2,3,1};
    vector<int>arr1={1,0,1,1};
    vector<int>arr2={1,2,3,1,2,3};
    int k=3;
    Solution ob;
    cout<<ob.containsNearbyDuplicate(arr2,2)<<endl;
}