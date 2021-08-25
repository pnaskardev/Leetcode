#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int counter=0,i=0;
        while(i<flowerbed.size() && n>0)
        {
            if(flowerbed[i]==0)
            {
                if(i==0)
                {
                    if(flowerbed.size()==1)
                    {
                        counter++;
                        if(counter==n)
                        {
                            return true;
                        }
                        else 
                        {
                            return false;
                        }
                    }
                    else if(flowerbed[i+1]==0)
                    {
                        flowerbed[i]=1;
                        counter++;
                   
                    }
                }
                else if(i==flowerbed.size()-1)
                {
                    if(flowerbed[i-1]==0)
                    {
                        flowerbed[i]=1;
                        counter++;
               
                    }
                }
                else
                {
                    if(flowerbed[i-1]==0 && flowerbed[i+1]==0)
                    {
                        flowerbed[i]=1;
                        counter++;
                    }
                }
            }
            i++;
        }
        /*for(int i=0;i<flowerbed.size();i++)
    {
        cout<<flowerbed[i]<<" ";
    }
    cout<<endl;*/
        if(counter>=n)
        {
            return true;
        }
        return false;
    }
};
int main(void)
{
    vector<int>arr={0,0,1,0,0};
    Solution ob;
    cout<<ob.canPlaceFlowers(arr,1)<<endl;
}