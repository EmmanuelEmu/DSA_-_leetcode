class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string temp = s;
        int count1 = 0;
        for (auto i = 1; i < n; i++) {
            if (temp[i] == temp[i - 1]) {
                count1++;
                temp[i] = temp[i - 1] == '0' ? '1' : '0';
            }
        }
        int count2 = 1;
        s[0] = s[0] == '0' ? '1' : '0';
        for (auto i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count2++;
                s[i] = s[i - 1] == '0' ? '1' : '0';
            }
        }
        return min(count1, count2);
    }
};