#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string text1, string text2)
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
    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
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

    // int len = dp[n][m];
    // int index = len - 1;
    string res = "";
    int i = n, j = m;
    // for (int i = 0; i < len; i++)
    //     res += '$';
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            // res[index] = text1[i - 1];
            res+=text1[i-1];
            i--;
            j--;
            // index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            res+=text1[i-1];
            i--;
        }
        else
        {
            res+=text2[j-1];
            j--;
        }
    }
    while(i>0){
        res+=text1[i-1];
        i--;
    }
    while(j>0){
        res+=text2[j-1];
        j--;
    }
    reverse(res.begin(), res.end());
    return res;
}

string shortestCommonSupersequence(string str1, string str2)
{
    return longestCommonSubsequence(str1, str2);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << shortestCommonSupersequence(s1, s2) << endl;
    return 0;
}