class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Code here
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxi = 1;
        int hash[n];
        int lastIndex = 0;
        for (auto i = 0; i < n; i++) {
            hash[i] = i;
            for (auto j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};