class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                if (st.empty())
                    nge.push_back(-1);
                else
                    nge.push_back(st.top());
            }
            st.push(nums[i % n]);
        }
        reverse(nge.begin(), nge.end());
        return nge;
    }
};