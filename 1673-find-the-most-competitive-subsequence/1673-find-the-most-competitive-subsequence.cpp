class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        int toRemove = n - k;
        int removed = 0;

        for (auto num : nums) {
            while (!st.empty() && num < st.top() && removed < toRemove) {
                st.pop();
                removed++;
            }
            st.push(num);
        }

        // If still extra elements, remove from top
        while (removed < toRemove) {
            st.pop();
            removed++;
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
