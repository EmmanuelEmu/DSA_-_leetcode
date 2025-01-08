class Solution {
public:
    bool isPrefix(string& a, string& b) {
        int n = a.size();
        int m = b.size();
        if (n > m) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    bool isSuffix(string& a, string& b) {
        int n = a.size();
        int m = b.size();
        if (n > m) {
            return false;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != b[m - n + i]) {
                return false;
            }
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (i != j) {
                    if (isPrefix(words[i], words[j]) &&
                        isSuffix(words[i], words[j])) {
                        // cout << words[i] << " " << words[j] << endl;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};