class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        map<char, int> charCount;
        map<char, bool> inStack;

        for (auto chr : s) {
            charCount[chr]++;
        }
        for (auto chr : s) {
            charCount[chr]--;
            if (!inStack[chr]) {
                while (!st.empty() && chr < st.top() &&
                       charCount[st.top()] > 0) {
                    inStack[st.top()] = false;
                    st.pop();
                }
                st.push(chr);
                inStack[chr] = true;
            }
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};