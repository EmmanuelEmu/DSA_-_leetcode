class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = pre[i][j - 1] + (nums[j - 1] < i);
            }
        }

        long long res = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[j] > nums[k]) {
                    long long potentialI = pre[nums[k]][j];
                    // Count how many nums[l] > nums[j] for l > k (valid l's)
                    long long potentialL = (n - nums[j]) - (k - pre[nums[j]][k + 1]);
                    res+=potentialI*potentialL;
                }
            }
        }

        return res;
    }
};