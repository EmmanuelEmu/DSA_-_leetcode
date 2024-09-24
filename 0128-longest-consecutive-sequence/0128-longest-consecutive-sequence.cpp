class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longest = 1;
        int count = 1;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] == nums[i - 1] + 1) {
                count++;
                longest = max(longest, count);
            } else {
                count = 1;
            }
        }
        return longest;
    }
};