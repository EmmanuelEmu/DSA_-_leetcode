#include <bits/stdc++.h>
using namespace std;


int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (auto i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (auto j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << numDistinct(s1, s2) << endl;
    return 0;
}