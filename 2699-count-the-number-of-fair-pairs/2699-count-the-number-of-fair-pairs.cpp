class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < n; i++) {
            auto lb = lower - nums[i];
            auto ub = upper - nums[i];

            auto lb_bound = lower_bound(nums.begin() + i + 1, nums.end(), lb);
            auto ub_bound = upper_bound(nums.begin() + i + 1, nums.end(), ub);

            count += ub_bound - lb_bound;
        }
        return count;
    }
};