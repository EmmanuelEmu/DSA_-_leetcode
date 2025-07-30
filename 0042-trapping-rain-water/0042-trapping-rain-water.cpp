class Solution {
public:
    vector<int> prefixMax(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        prefix[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        return prefix;
    }

    vector<int> suffixMax(vector<int>& height) {
        int n = height.size();
        vector<int> suffix(n);
        suffix[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            suffix[j] = max(suffix[j + 1], height[j]);
        }
        return suffix;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix = prefixMax(height);
        vector<int> suffix = suffixMax(height);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(prefix[i], suffix[i]) - height[i];
        }
        return ans;
    }
};