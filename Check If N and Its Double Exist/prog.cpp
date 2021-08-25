#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        unordered_map<int,int>::iterator it;
        for(int i=0;i<arr.size();i++)
        {
            mp.insert({arr[i],i});
        }
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(2*arr[i])!=mp.end())
            {
                it=mp.find(2*arr[i]);
                if(it->second==i)
                {
                    continue;
                }
                else
                {
                    return true;
                }
            }
        } 
        return false;    
    }
};
int32_t main(void)
{
    vector<int>arr1={10,2,5,3};  
    vector<int>arr2={7,1,14,11};    
    vector<int>arr3={3,1,7,11};
    vector<int>arr4={-10,12,-20,-8,15};
    vector<int>arr5={102,-592,457,802,98,-132,883,356,-857,461,-453,522,250,476,991,540,-852,-485,-637,999,-803,-691,-880,881,-584,750,-124,745,-909,-892,304,-814,868,665,50,-40,26,-242,-797,-360,-918,-741,88,-933,-93,360,-738,833,-191,563,449,840,806,-87,-950,508,74,-448,-815,-488,639,-334};
    vector<int>arr6={-2,0,10,-19,4,6,-8};
    Solution ob;
    cout<<ob.checkIfExist(arr3)<<endl;
}