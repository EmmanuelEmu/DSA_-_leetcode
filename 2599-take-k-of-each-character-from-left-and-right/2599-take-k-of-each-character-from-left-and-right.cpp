class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) {
            return 0;
        }
        int n = s.size();
        map<char, int> count;
        for (char ch : s) {
            count[ch]++;
        }
        if (count['a'] < k || count['b'] < k || count['c'] < k) {
            return -1;
        }

        int requiredA = count['a'] - k;
        int requiredB = count['b'] - k;
        int requiredC = count['c'] - k;
        int l = 0, maxWindowLength = 0;
        map<char, int> window;

        for (int r = 0; r < n; ++r) {
            window[s[r]]++;

            while (window['a'] > requiredA || window['b'] > requiredB ||
                   window['c'] > requiredC) {
                window[s[l]]--;
                l++;
            }
            maxWindowLength = max(maxWindowLength, r - l + 1);
        }
        return n - maxWindowLength;
    }
};