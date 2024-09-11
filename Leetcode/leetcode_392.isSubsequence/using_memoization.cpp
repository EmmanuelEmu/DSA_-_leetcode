#include <bits/stdc++.h>
using namespace std;

bool solve(string &s, string &t, int i, int ind, int n, vector<vector<int>> &dp)
{
    // If we have fully matched 's', return true
    if (i == s.size()) {
        return true;
    }

    // If we've reached the end of 't' without matching all of 's', return false
    if (ind == n) {
        return false;
    }

    // Check if this state has been solved before
    if (dp[i][ind] != -1) {
        return dp[i][ind];
    }

    // If the current characters match, try to match the next character in both 's' and 't'
    if (s[i] == t[ind]) {
        return dp[i][ind] = solve(s, t, i + 1, ind + 1, n, dp);
    }

    // Else skip the current character in 't' and check for subsequence
    return dp[i][ind] = solve(s, t, i, ind + 1, n, dp);
}

bool isSubsequence(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1)); // Memoization table
    return solve(s, t, 0, 0, t.size(), dp);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << isSubsequence(s, t) << endl;
    return 0;
}
