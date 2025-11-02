class Solution {
public:
    int solve(int k, vector<int>& nums, int sum, int n, vector<int>& dp) {
        if (k == 0) {
            int result = 0;
            for (int i = 0; i < n; i++) {
                result += i * nums[i];
            }
            return result;
        }
        if (dp[k] != INT_MIN)
            return dp[k];
        return dp[k] = solve(k - 1, nums, sum, n, dp) + sum - nums.size() * nums[n - k];
    }

    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int> dp(n+1, INT_MIN);
        solve(n, nums, sum, n, dp);
        int result = *max_element(dp.begin(), dp.end());
        return result;
    }
};