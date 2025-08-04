class Solution {
public:
    string trimmingHeaderZeros(string num) {
        int id = 0;
        while (id < num.size() && num[id] == '0') {
            num.erase(id, 1);
        }
        return (num.size() == 0) ? "0" : num;
    }

    string removeKdigits(string num, int k) {
        num = trimmingHeaderZeros(num);
        int n = num.size();

        stack<char> st;
        for (int i = 0; i < n; ++i) {
            char digit = num[i];
            while (!st.empty() && st.top() > digit && k > 0) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        result = trimmingHeaderZeros(result);

        return result;
    }
};