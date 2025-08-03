class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int lb = 0, ub = n - 1;
        while (lb < ub) {
            swap(s[lb], s[ub]);
            lb++;
            ub--;
        }
    }
};