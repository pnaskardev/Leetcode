#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int maxArea=0;
        int left=0,right=height.size()-1;
        while(left<right)
        {
            int VerticalHeight=min(height[left],height[right]);
            int HorizontalDistance=abs(left-right);
            int Area=VerticalHeight*HorizontalDistance;
            maxArea=max(Area,maxArea);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};
int main(void)
{
    vector<int>arr={1,8,6,2,5,4,8,3,7};
    Solution ob;
    cout<<ob.maxArea(arr)<<endl;
}