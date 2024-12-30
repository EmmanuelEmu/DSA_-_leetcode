#include <bits/stdc++.h>
using namespace std;


// This code has the sliding window issue

// int takeCharacters(string s, int k)
// {
//     cout << s << " " << k << endl;
//     if (k == 0)
//     {
//         return 0;
//     }
//     int n = s.size();
//     int l = 0, r = 0;
//     map<char, int> mp;
//     for (auto ch : s)
//     {
//         mp[ch]++;
//     }
//     if (mp['a'] < k || mp['b'] < k || mp['c'] < k)
//     {
//         return -1;
//     }
//     int minLen = s.size();
//     while (r < n)
//     {
//         mp[s[r]]--;
//         while (l <= r && (mp['a'] < k || mp['b'] < k || mp['c'] < k))
//         {
//             mp[s[l]]++;
//             l++;
//         }
//         if (mp['a'] >= k && mp['b'] >= k && mp['c'] >= k)
//         {
//             minLen = min(minLen, r - l + 1);
//         }
//         r++;
//     }
//     return minLen == s.size() ? -1 : minLen;
// }



int takeCharacters(string s, int k) {
    if (k == 0) {
        return 0;
    }

    int n = s.size();
    map<char, int> count;

    // Count total occurrences of each character
    for (char ch : s) {
        count[ch]++;
    }

    // Check if it's impossible to satisfy the condition
    if (count['a'] < k || count['b'] < k || count['c'] < k) {
        return -1;
    }

    // Required counts for each character
    int requiredA = count['a'] - k;
    int requiredB = count['b'] - k;
    int requiredC = count['c'] - k;

    // Sliding window to find the maximum valid window
    int l = 0, maxWindowLength = 0;
    map<char, int> window;

    for (int r = 0; r < n; ++r) {
        window[s[r]]++;

        // Ensure the window does not exceed the "required" counts
        while (window['a'] > requiredA || window['b'] > requiredB || window['c'] > requiredC) {
            window[s[l]]--;
            l++;
        }

        // Update the maximum window length
        maxWindowLength = max(maxWindowLength, r - l + 1);
    }

    // Minimum characters to remove
    return n - maxWindowLength;
}



int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << takeCharacters(s, k) << endl;
    return 0;
}