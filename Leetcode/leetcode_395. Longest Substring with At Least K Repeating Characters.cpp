#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    int n = s.size();
    int maxlen = 0;

    for (int i = 0; i < n; i++) {
        map<char, int> hash;
        int validChars = 0;
        int uniqueChars = 0;

        for (int j = i; j < n; j++) {
            hash[s[j]]++;

            if (hash[s[j]] == 1) uniqueChars++;

            if (hash[s[j]] == k) validChars++;

            if (uniqueChars == validChars) {
                maxlen = max(maxlen, j - i + 1);
            }
        }
    }
    return maxlen;
}


int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << longestSubstring(s, k) << endl;
    return 0;
}