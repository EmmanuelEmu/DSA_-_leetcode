class Solution {
public:
    int countVowels(string s) {
        int n = s.size();
        if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' ||
             s[0] == 'u') &&
            (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' ||
             s[n - 1] == 'o' || s[n - 1] == 'u')) {
            return 1;
        } else {
            return 0;
        }
    }

    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> preCompute(n + 1, 0);
        int sum = 0;
        for (auto i = 0; i < n; i++) {
            sum += countVowels(words[i]);
            preCompute[i] = sum;
        }
        for (auto i = 0; i <= n; i++) {
            cout << preCompute[i] << " ";
        }
        cout << endl;
        vector<int> ans;

        for (auto i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == 0) {
                ans.push_back(preCompute[r]);
            } else {
                ans.push_back(preCompute[r] - preCompute[l - 1]);
            }
        }
        return ans;
    }
};