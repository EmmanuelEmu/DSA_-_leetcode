class Solution {
public:
    int maxNum(vector<int>& nums, int ind, int lastIndex,
               vector<vector<int>>& dp) {
        if (ind < 0) {
            return 0;
        }
        if (dp[ind][lastIndex + 1] != -1) {
            return dp[ind][lastIndex + 1];
        }
        int notTake = maxNum(nums, ind - 1, lastIndex, dp);
        int take = INT_MIN;
        if (lastIndex == -1 || nums[ind] < nums[lastIndex])
            take = 1 + maxNum(nums, ind - 1, ind, dp);
        return dp[ind][lastIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return maxNum(nums, nums.size() - 1, -1, dp);
    }
};