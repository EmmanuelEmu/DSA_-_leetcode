class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;
        for (auto it : nums) {
            totalSum += it;
        }

        for (auto i = 0; i < nums.size(); i++) {
            if (totalSum - nums[i] - leftSum == leftSum) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};