#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {

        if (arr.size() == 1)
            return arr[0];
        else
        {
            int l = 0, r = arr.size()-1;
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                // cout << "mid->" << m << endl;
                if (arr[m] > arr[r])
                    l = m;
                else
                    r = m;
            }
            // cout << l << " " << r << endl;
            return min(arr[l], arr[r]);
        }
    }
};

int main(void)
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> arr = {3, 4, 5, 1, 2};
    // vector<int> arr = {11,13,15,17};
    Solution ob;
    cout << ob.findMin(arr) << endl;
}