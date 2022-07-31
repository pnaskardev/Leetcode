#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(arr[i]*2)!=mp.end())
            {
                return true;
            }
            else if(arr[i]%2==0 && mp.find(arr[i]/2)!=mp.end())
            {
                return true;
            }
            else
            {
                mp[arr[i]]++;
            }
            
        }    
        return false;
    }
};
int main(void)
{
    vector<int>arr={10,2,5,3};
    vector<int>arr1={7,1,14,11};
    vector<int>arr2={3,1,7,11};

    Solution ob;
    cout<<ob.checkIfExist(arr2)<<endl;
}