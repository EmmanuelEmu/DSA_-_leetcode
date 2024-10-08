#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, int start, int end)
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

int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n, INT_MAX);

    // Precompute palindrome information in a 2D array
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));

    // Precompute all substrings to check if they are palindromes
    for (int end = 0; end < n; end++)
    {
        for (int start = 0; start <= end; start++)
        {
            if (s[start] == s[end] && (end - start <= 1 || isPalin[start + 1][end - 1]))
            {
                isPalin[start][end] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isPalin[0][i])
        {
            dp[i] = 0;
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (isPalin[j + 1][i])
                {
                    dp[i] = min(dp[i], dp[j] + 1); // Add one cut if s[j+1...i] is a palindrome
                }
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << minCut(s) << endl;
    return 0;
}
