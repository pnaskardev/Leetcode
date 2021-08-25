#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        
        int i=0;
        while(i<flowerbed.size() && n>0)
        {
            
            if(flowerbed[i]!=1)
            {
                
                if(i==0)
                {
                    if(flowerbed.size()==1){
                        n-=1;
                        if(n==0){
                            return true;
                        }
                        else{
                            return false;
                        }
                    }
                    if(flowerbed[i+1]!=1)
                    {
                        n-=1;
                        flowerbed[i]=1;
                    }
                }
                else if(i==flowerbed.size()-1)
                {
                    
                        if(flowerbed[i-1]!=1)
                        {
                            
                            n-=1;
                            flowerbed[i]=1;
                        }
                }
                else
                {
                    if(flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                        n-=1;
                        flowerbed[i]=1;
                    }
                        
                }
                
            }
            
            
            i+=1;
        }
        for(int i=0;i<flowerbed.size();i++)
    {
        cout<<flowerbed[i]<<" ";
    }
    cout<<endl;
        return n==0;
    }
        
    
};

int main(void)
{
    vector<int>arr={1,0,0,0,1};
    Solution ob;
    cout<<ob.canPlaceFlowers(arr,1)<<endl;
    /*for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/
}