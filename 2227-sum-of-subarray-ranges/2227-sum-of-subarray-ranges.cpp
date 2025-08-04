class Solution {
public:
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

    vector<int> rightGreaterElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
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
    vector<int> leftGreaterElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
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

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long minSum = 0;
        long long maxSum = 0;
        vector<int> minleft = leftSmallerElement(nums);
        vector<int> minright = rightSmallerElement(nums);
        vector<int> maxleft = leftGreaterElement(nums);
        vector<int> maxright = rightGreaterElement(nums);

        for (int i = 0; i < n; i++) {
            minSum = (minSum + (1LL * nums[i] * minleft[i] * minright[i]));
            maxSum = (maxSum + (1LL * nums[i] * maxleft[i] * maxright[i]));
        }
        return maxSum - minSum;
    }
};