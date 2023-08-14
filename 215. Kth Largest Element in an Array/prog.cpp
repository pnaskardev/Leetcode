#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (auto i : nums)
            pq.push(i);

        int ans = 0;
        for (int i = 0; i < k - 1; i++)
            pq.pop();
        ans = pq.top();
        return ans;
    }
};

int main(void)
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Solution ob;
    cout << ob.findKthLargest(arr, 2) << endl;
}