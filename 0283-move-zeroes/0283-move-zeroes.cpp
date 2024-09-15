class Solution {
public:
    // Optimal Solution
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeroInd = -1;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroInd = i;
                break;
            }
        }

        if (zeroInd != -1) {
            for (auto i = zeroInd + 1; i < n; i++) {
                if (nums[i] != 0) {
                    swap(nums[i], nums[zeroInd]);
                    zeroInd++;
                }
            }
        }
    }
};