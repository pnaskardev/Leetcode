#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class bucket
{
    private:
    forward_list<int>container;
    public:
    void insert(int key)
    {
        if(std::find(container.begin(),container.end(),key)==container.end())
        {
            container.push_front(key);
        }
    }
    void erase(int key)
    {
        container.remove(key);
    }
    bool exists(int key)
    {
        if(std::find(container.begin(),container.end(),key)!=container.end())
        {
            return true;
        }
        return false;
    }
};
class MyHashSet 
{   
    private:
    int range=769;
    bucket arr[769];
public:
    /** Initialize your data structure here. */
    MyHashSet() 
    {
        
    }
    void add(int key) 
    {
        arr[key%range].insert(key);
    }
    void remove(int key) 
    {
        arr[key%range].erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        return arr[key%range].exists(key);
    }
};
int main(void)
{

}
