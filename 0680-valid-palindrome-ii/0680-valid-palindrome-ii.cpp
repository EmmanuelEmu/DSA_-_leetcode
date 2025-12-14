class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                auto isPalindrome = [&](int l, int r) {
                    while (l < r) {
                        if (s[l] != s[r])
                            return false;
                        ++l;
                        --r;
                    }
                    return true;
                };
                return isPalindrome(left + 1, right) ||
                       isPalindrome(left, right - 1);
            }
            ++left;
            --right;
        }
        return true;
    }
};