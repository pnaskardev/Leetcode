#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] == true)
                {
                    string word = s.substr(j, i - j);
                    if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

int main(void)
{
    vector<string> wordDict = {
        "leet", "code"};

    string s = "leetcode";

    Solution ob;
    cout << ob.wordBreak(s, wordDict) << endl;
}