class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int totalCount = 0;
        for (auto bitIndex = 0; bitIndex < 32; bitIndex++) {
            int ones = 0;
            for (auto it : nums) {
                if (it & (1 << bitIndex)) {
                    ones++;
                }
            }
            totalCount += ones * (nums.size() - ones);
        }

        return totalCount;
    }
};