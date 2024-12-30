#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest common supersequence of two strings
string shortestCommonSupersequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the dp array using the LCS approach
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the shortest common supersequence
    string res = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            res += text1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            res += text1[i - 1];
            i--;
        }
        else
        {
            res += text2[j - 1];
            j--;
        }
    }
    // Add remaining characters from either string
    while (i > 0)
    {
        res += text1[i - 1];
        i--;
    }
    while (j > 0)
    {
        res += text2[j - 1];
        j--;
    }

    // Reverse the result to get the correct sequence
    reverse(res.begin(), res.end());
    return res;
}

string minimumString(string a, string b, string c)
{
    // Find the shortest common supersequence for all three strings
    string res = shortestCommonSupersequence(a, b);
    return shortestCommonSupersequence(res, c);
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << minimumString(s1, s2, s3) << endl;
    return 0;
}
