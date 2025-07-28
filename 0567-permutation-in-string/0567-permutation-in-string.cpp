class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_len = s1.size(), s2_len = s2.size();
        if (s1_len > s2_len)
            return false;
        map<char, int> s1_count, s2_count;
        for (char c : s1) {
            s1_count[c - 'a']++;
        }
        for (auto i = 0; i < s2_len; i++) {
            s2_count[s2[i] - 'a']++;
            if (i >= s1_len) {
                s2_count[s2[i - s1_len] - 'a']--;
                if (s2_count[s2[i - s1_len] - 'a'] == 0) {
                    s2_count.erase(s2[i - s1_len] - 'a');
                }
            }
            if (s2_count == s1_count) {
                return true;
            }
        }
        return false;
    }
};