class Solution {
public:
    string solve(string s, int n, int iteration) {
        if (iteration == n)
            return s;

        string result = "";
        int i = 0;
        while (i < s.size()) {
            int count = 1;
            while (i + 1 < s.size() && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            result += to_string(count) + s[i];
            i++;
        }

        return solve(result, n, iteration + 1);
    }

    string countAndSay(int n) {
        if (n == 1)
            return "1";
        return solve("1", n, 1);
    }
};