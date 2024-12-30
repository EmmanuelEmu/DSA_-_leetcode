#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // applying shifting technique to avoid the -1 based indexing
    for (auto i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (auto j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    int ans = 0;
    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    for (auto i = 0; i <= n; i++)
    {
        for (auto j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubstring(s1, s2) << endl;
    return 0;
}