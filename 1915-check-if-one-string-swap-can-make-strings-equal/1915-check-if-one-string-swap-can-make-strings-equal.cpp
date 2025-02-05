class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        int i = 0, j = s1.size() - 1;
        int count = 0;

        while (i < j) {
            if (s1[i] != s2[i]) {
                break;
            }
            i++;
        }
        while (j > i) {
            if (s1[j] != s2[j]) {
                break;
            }
            j--;
        }
        swap(s1[i], s1[j]);
        if (s1 == s2)
            return true;
        return false;
    }
};