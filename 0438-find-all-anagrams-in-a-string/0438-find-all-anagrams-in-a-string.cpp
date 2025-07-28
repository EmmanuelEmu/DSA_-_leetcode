class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int s_len = s.size(), p_len = p.size();
        if (s_len < p_len)
            return result;
        map<char, int> p_count, s_count;
        for (char c : p) {
            p_count[c - 'a']++;
        }
        for (auto i = 0; i < s_len; i++) {
            s_count[s[i] - 'a']++;
            if (i >= p_len) {
                s_count[s[i - p_len] - 'a']--;
                if (s_count[s[i - p_len] - 'a'] == 0) {
                    s_count.erase(s[i - p_len] - 'a');
                }
            }
            if (s_count == p_count) {
                result.push_back(i - p_len + 1);
            }
        }
        return result;
    }
};