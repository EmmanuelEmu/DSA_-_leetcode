#include <bits/stdc++.h>
using namespace std;

// Function to remove LCS characters from the original string one by one
string removeLCSCharacters(string s, string lcs) {
    int lcsIndex = 0;  // Track the index of LCS characters
    string result = "";

    for (char c : s) {
        if (lcsIndex < lcs.size() && c == lcs[lcsIndex]) {
            lcsIndex++;  // Skip this character, as it's part of the LCS
        } else {
            result += c;  // Keep this character
        }
    }

    return result;
}

// Function to find all LCS (Longest Common Subsequences)
void findAllLCS(vector<vector<int>> &dp, string &text1, string &text2, int i, int j, string currentLCS, set<string> &allLCS) {
    if (i == 0 || j == 0) {
        reverse(currentLCS.begin(), currentLCS.end());
        allLCS.insert(currentLCS);
        return;
    }

    if (text1[i - 1] == text2[j - 1]) {
        findAllLCS(dp, text1, text2, i - 1, j - 1, currentLCS + text1[i - 1], allLCS);
    } else {
        if (dp[i - 1][j] == dp[i][j]) {
            findAllLCS(dp, text1, text2, i - 1, j, currentLCS, allLCS);
        }
        if (dp[i][j - 1] == dp[i][j]) {
            findAllLCS(dp, text1, text2, i, j - 1, currentLCS, allLCS);
        }
    }
}

// Function to find the LCS of two strings
set<string> allLongestCommonSubsequences(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // To store all LCSs
    set<string> allLCS;

    // Backtrack to find all LCSs
    findAllLCS(dp, text1, text2, n, m, "", allLCS);

    return allLCS;
}

// Function to calculate minimum ASCII delete sum
int minimumDeleteSum(string s1, string s2) {
    set<string> allLCS = allLongestCommonSubsequences(s1, s2);
    int minValue = INT_MAX;

    for (auto &lcs : allLCS) {
        // Remove LCS characters one by one from the strings
        string res1 = removeLCSCharacters(s1, lcs);
        string res2 = removeLCSCharacters(s2, lcs);

        cout << "Remaining after removing LCS '" << lcs << "': " << res1 << " " << res2 << endl;

        // Calculate ASCII sum of remaining characters
        int asciiValue = 0;
        for (char c : res1) asciiValue += (int)c;
        for (char c : res2) asciiValue += (int)c;

        // Keep track of the minimum ASCII sum
        minValue = min(minValue, asciiValue);
    }

    return minValue;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Find all LCSs and print them
    set<string> result = allLongestCommonSubsequences(s1, s2);
    cout << "All LCSs: \n";
    for (auto &lcs : result) {
        cout << lcs << endl;
    }

    // Calculate and print the minimum ASCII delete sum
    int res = minimumDeleteSum(s1, s2);
    cout << "Minimum ASCII delete sum: " << res << endl;

    return 0;
}
