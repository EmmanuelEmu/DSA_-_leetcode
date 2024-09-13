class Solution {
public:
    bool solve(vector<int>& nums, int ind, int sum, vector<vector<int>>& dp) {

        if (sum == 0) {
            return true;
        }
        if (ind == 0) {
            return sum == nums[0];
        }
        if (dp[ind][sum] != -1) {
            return dp[ind][sum];
        }

        bool notTake = solve(nums, ind - 1, sum, dp);
        bool take = false;
        if (nums[ind] <= sum) {
            take = solve(nums, ind - 1, sum - nums[ind], dp);
        }
        return dp[ind][sum] = notTake || take;
    }

    bool canPartition(vector<int>& nums) {
        // if (nums.size() % 2 != 0) {
        //     return false;
        // }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        // cout << sum / 2 << endl;
        return solve(nums, nums.size() - 1, target, dp);
    }
};