#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class RandomizedSet {
    private:
    unordered_map<int, int> mp;
    vector<int> arr;
    int size = 0;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.count(val) != 0)
        {
            return false;
        }
        mp[val] = size;
        arr.push_back(val);
        size++;
        
        return true;
    }
    
    bool remove(int val) {
        if (mp.count(val) == 0)
        {
            return false;
        }
        int idx = mp[val];
        arr[idx] = arr[size - 1];
        arr.pop_back();
        mp[arr[idx]] = idx;
        mp.erase(val);
        size--;
        return true;
    }
    
    int getRandom() {
        return arr[rand() % size];
    }
    

};
int main(void)
{
    
}