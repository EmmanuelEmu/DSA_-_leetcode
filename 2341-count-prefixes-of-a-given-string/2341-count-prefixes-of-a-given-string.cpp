class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (auto string : words) {
            if (s.find(string) == 0) {
                count++;
            }
        }
        return count;
    }
};