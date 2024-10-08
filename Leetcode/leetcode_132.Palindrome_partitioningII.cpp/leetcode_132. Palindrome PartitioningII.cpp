#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int solve(int ind, string s, vector<int> &dp)
{
    if (ind == s.size())
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int result = INT_MAX;
    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            int cut = 1 + solve(i + 1, s, dp);
            result = min(result, cut);
        }
    }

    return dp[ind] = result;
}

int minCut(string s)
{
    vector<int> dp(s.size(), -1);
    return solve(0, s, dp)-1;
}

int main()
{
    string s;
    cin >> s;
    cout << minCut(s) << endl;
    return 0;
}