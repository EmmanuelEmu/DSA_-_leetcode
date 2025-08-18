class Solution {
public:
    int pow2(int b) {
        if (b == 0)
            return 1;
        int half = pow2(b / 2);
        return (b % 2 == 0) ? half * half : 2 * half * half;
    }

    int scoreOfParentheses(string s) {
        int totalScore = 0;
        int score = 0;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                st.pop();
                // check if it’s a "()" pair
                if (i > 0 && s[i - 1] == '(') {
                    totalScore += pow2(st.size());
                }
            }
        }
        return totalScore;
    }
};