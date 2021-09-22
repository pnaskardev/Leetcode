#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) 
    {
        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(),bobSizes.end());
        int sumal=0;
        for(int i=0;i<aliceSizes.size();i++)
        {
            sumal=sumal+aliceSizes[i];
        }
        int sumbob=0;
        for(int i=0;i<bobSizes.size();i++)
        {
            sumbob+=bobSizes[i];
        }
        int diff=(sumbob-sumal)/2;
        vector<int>res;
        for(auto x:aliceSizes)
        {
            int idx=lower_bound(bobSizes.begin(),bobSizes.end(),diff+x)-bobSizes.begin();
            if(bobSizes[idx]==diff+x)
            {
                res.push_back(x);
                res.push_back(diff+x);
                break;
            }
        }
        return res;
    }
};
int main(void)
{
    vector<int>alice={1,2,5};
    vector<int>bob={2,4};
    Solution ob;
    ob.fairCandySwap(alice,bob);
}