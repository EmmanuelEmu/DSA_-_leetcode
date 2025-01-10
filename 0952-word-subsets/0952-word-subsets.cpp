class Solution {
public:
    vector<int> count(string& s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        return freq;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq(26, 0);
        for (auto it : words2) {
            vector<int> temp = count(it);
            for (int i = 0; i < 26; i++) {
                freq[i] = max(freq[i], temp[i]);
            }
        }
        for (auto it : words1) {
            vector<int> temp = count(it);
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (temp[i] < freq[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(it);
            }
        }
        return result;
    }
};