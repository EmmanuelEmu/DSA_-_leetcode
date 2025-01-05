class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> prefixSum(n + 1, 0);
        for (auto shift : shifts) {
            prefixSum[shift[0]] += (shift[2] == 1) ? 1 : -1;
            prefixSum[shift[1] + 1] -= (shift[2] == 1) ? 1 : -1;
        }

        int shiftSum = 0;
        for (int i = 0; i < n; i++) {
            shiftSum += (prefixSum[i] % 26 + 26) %
                        26;
            s[i] =
                (s[i] - 'a' + shiftSum) % 26 + 'a';
        }

        return s;
    }
};