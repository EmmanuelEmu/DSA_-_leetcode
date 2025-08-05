class Solution {
public:
    vector<int> previousSmallerElement(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ps(n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ps[i] = -1;
            } else {
                ps[i] = st.top();
            }
            st.push(i);
        }
        return ps;
    }

    vector<int> nextSmallerElement(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ns(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ns[i] = n;
            } else {
                ns[i] = st.top();
            }
            st.push(i);
        }
        return ns;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ps = previousSmallerElement(heights);
        vector<int> ns = nextSmallerElement(heights);
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int area = heights[i] * (ns[i] - ps[i] - 1);
            ans = max(ans, area);
        }
        return ans;
    }
};