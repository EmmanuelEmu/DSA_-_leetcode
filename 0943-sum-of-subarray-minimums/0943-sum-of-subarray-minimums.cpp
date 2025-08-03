class Solution {
public:
    #define MOD 1000000007
    vector<int> rightSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n - i;
            } else {
                ans[i] = st.top() - i;
            }
            st.push(i); // Fix: Push index
        }
        return ans;
    }

    vector<int> leftSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = i + 1;
            } else {
                ans[i] = i - st.top();
            }
            st.push(i); // Fix: Push index
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int> left = leftSmallerElement(arr);
        vector<int> right = rightSmallerElement(arr);
        for (int i = 0; i < n; i++) {
            sum = (sum + (1LL * arr[i] * left[i] * right[i]) % MOD) % MOD;
        }
        return sum;
    }
};