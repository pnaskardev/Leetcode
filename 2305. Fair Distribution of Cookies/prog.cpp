#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int ans = INT_MAX;
    void helper(vector<int> &cookies, vector<int> &children, int start)
    {
        int n = cookies.size();

        if (start == n)
        {
            int maxm = INT_MIN;
            for (int i = 0; i < children.size(); i++)
            {
                maxm = max(maxm, children[i]);
            }
            ans = min(ans, maxm);
            return;
        }

        for (int i = 0; i < children.size(); i++)
        {
            children[i] += cookies[start];
            helper(cookies, children, start + 1);
            children[i] -= cookies[start];
        }
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> children(k, 0);
        helper(cookies, children, 0);
        return ans;
    }
};

int main(void)
{
    vector<int> cookies = {8, 15, 10, 20, 8};
    int k = 2;
    Solution ob;
    cout << ob.distributeCookies(cookies, k) << endl;
}