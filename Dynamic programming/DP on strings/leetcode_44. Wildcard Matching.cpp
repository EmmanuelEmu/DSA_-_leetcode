#include <bits/stdc++.h>
using namespace std;

bool solve(int ind1, int ind2, string &s, string &p, vector<vector<int>> &dp)
{
    if (ind1 < 0 && ind2 < 0)
        return true;
    if (ind1 < 0 && ind2 >= 0)
        return false;
    if (ind2 < 0 && ind1 >= 0)
    {
        for (int i = 0; i <= ind1; i++)
        {
            if (s[i] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s[ind1] == p[ind2] || s[ind1] == '?')
    {
        return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, s, p, dp);
    }
    if (s[ind1] == '*')
    {
        return dp[ind1][ind2] = solve(ind1 - 1, ind2, s, p, dp) | solve(ind1, ind2 - 1, s, p, dp);
    }
    return dp[ind1][ind2] = false;
}

bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(m - 1, n - 1, p, s, dp);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << isMatch(s1, s2) << endl;
    return 0;
}