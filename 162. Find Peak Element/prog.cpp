#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int findPeakElement(vector<int>& nums) 
        {
            auto pred=[&](int i)
            {
                return (i==0 || nums[i]>nums[i-1]);
            };

            if(nums.size()==1)
            {
                return 0;
            }
            else
            {
                int l=-1,r=nums.size();
                while(r-l>1)
                {
                    int mid=(l+r)/2;
                    if(pred(mid))
                    {
                        l=mid;
                    }
                    else
                    {
                        r=mid;
                    }
                }
                return l;
            }
        }
};

int main(void)
{
    // vector<int> arr = {1,2,3,1};
    vector<int> arr = {1,2,1,3,5,6,4};
    Solution ob;
    cout << ob.findPeakElement(arr) << endl;
}