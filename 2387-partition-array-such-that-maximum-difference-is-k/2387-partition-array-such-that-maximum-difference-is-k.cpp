class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lb = 0, ub = 0;
        int count = 1;

        while (ub < n) {
            if (nums[ub] - nums[lb] > k) {
                count++;
                while (lb < ub) {
                    lb++;
                }
            }
            ub++;
        }
        return count;
    }
};