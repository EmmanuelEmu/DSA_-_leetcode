#include <bits/stdc++.h>
using namespace std;

string removeLCSCharacters(string s, string lcs)
{
    int lcsIndex = 0; // Track the index of LCS characters
    string result = "";

    for (char c : s)
    {
        if (lcsIndex < lcs.size() && c == lcs[lcsIndex])
        {
            lcsIndex++; // Skip this character, as it's part of the LCS
        }
        else
        {
            result += c; // Keep this character
        }
    }

    return result;
}
// Function to find the LCS with maximum ASCII value
string findMaxAsciiLCS(string &text1, string &text2)
{
    int n = text1.size();
    int m = text2.size();

    // DP table to store the maximum ASCII sum of LCS for substrings text1[0..i-1] and text2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                // If characters match, add their ASCII value to the LCS sum
                dp[i][j] = dp[i - 1][j - 1] + (int)text1[i - 1];
            }
            else
            {
                // Otherwise, take the maximum ASCII value sum from the previous states
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to construct the LCS with maximum ASCII value
    string maxAsciiLCS = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            maxAsciiLCS += text1[i - 1]; // If characters match, add it to the result
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--; // Move upwards in the DP table
        }
        else
        {
            j--; // Move leftwards in the DP table
        }
    }

    reverse(maxAsciiLCS.begin(), maxAsciiLCS.end()); // LCS was built backwards, reverse it
    return maxAsciiLCS;
}

// Function to calculate the ASCII value of a string
int calculateAsciiSum(string &str)
{
    int sum = 0;
    for (char c : str)
    {
        sum += (int)c;
    }
    return sum;
}

int minimumDeleteSum(string s1, string s2)
{
    string maxAsciiLCS = findMaxAsciiLCS(s1, s2);
    string res1 = removeLCSCharacters(s1, maxAsciiLCS);
    string res2 = removeLCSCharacters(s2, maxAsciiLCS);

    int resVal = calculateAsciiSum(res1) + calculateAsciiSum(res2);

    return resVal;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    // Find the maximum ASCII value LCS
    string maxAsciiLCS = findMaxAsciiLCS(s1, s2);
    int res = minimumDeleteSum(s1, s2);
    cout << res << endl;
    // Output the result
    cout << "Max ASCII value LCS: " << maxAsciiLCS << endl;
    cout << "ASCII sum: " << calculateAsciiSum(maxAsciiLCS) << endl;

    return 0;
}
