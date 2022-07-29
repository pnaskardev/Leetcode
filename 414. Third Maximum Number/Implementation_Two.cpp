#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int thirdMax(vector<int>& nums)
    {
        priority_queue<int>PriorityQueue(nums.begin(),nums.end());
        if(PriorityQueue.size()<3)
        {
            return PriorityQueue.top();
        }
        else
        {
            int i;
            int CurrentTop,PreviousTop=INT_MAX,Maximum=PriorityQueue.top();
            for(i=0;i<3;i++)
            {
                CurrentTop=PriorityQueue.top();
                PriorityQueue.pop();
                if(CurrentTop==PreviousTop)
                {
                    i--;
                }
                PreviousTop=CurrentTop;

                if(PriorityQueue.empty())
                {
                    break;
                }
            }
            
            if(i<2)
            {
                return Maximum;
            }

            return CurrentTop;

        }
    }
};
int main(void)
{
    Solution ob;
    vector<int>arr={3,2,1};
    vector<int>arr1={2,1};
    vector<int>arr2={2,2,3,1};
    vector<int>arr3={1,2};

    cout<<ob.thirdMax(arr2)<<endl;
}