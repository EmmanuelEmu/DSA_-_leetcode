class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;
        vector<int> nge;
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty())
                nge.push_back(-1);
            else
                nge.push_back(st.top());
            st.push(nums2[i]);
        }
        reverse(nge.begin(), nge.end());
        for (int i = 0; i < n2; i++) {
            mp[nums2[i]] = nge[i];
        }
        for (int i = 0; i < n1; i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};