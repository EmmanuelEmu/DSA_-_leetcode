#include <bits/stdc++.h>
using namespace std;

int solve(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (ind1 < 0)
        return ind2 + 1;
    if (ind2 < 0)
        return ind1 + 1;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s1[ind1] == s2[ind2])
    {
        return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, s1, s2, dp);
    }
    return dp[ind1][ind2] = 1 + min(min(solve(ind1 - 1, ind2, s1, s2, dp), solve(ind1, ind2 - 1, s1, s2, dp)), solve(ind1 - 1, ind2 - 1, s1, s2, dp));
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n - 1, m - 1, word1, word2, dp);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minDistance(s1, s2) << endl;
    return 0;
}