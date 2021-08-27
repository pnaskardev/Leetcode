#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int p1 = m-1, p2 = n-1;
        for(int i = m+n-1;i >= 0;i--)
        {
	        if(p1 >= 0 && p2 >= 0)
            {
                if(nums1[p1]>nums2[p2])
                {
                    nums1[i]=nums1[p1];
                    p1--;
                }
                else
                {
                    nums1[i]=nums2[p2];
                    p2--;
                }
	        }
            else 
            {
                if(p1<0)
                {
                    nums1[i]=nums2[p2];
                    p2--;
                }
                else
                {
                    nums1[i]=nums1[p1];
                    p1--;
                }
	        }
        }    
    }
};
int32_t main(void)
{
    vector<int>arr1={1,2,3,0,0,0};  
    vector<int>arr2={2,5,6};    
    Solution ob;
    ob.merge(arr1,3,arr2,3);
    for(auto i:arr1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}