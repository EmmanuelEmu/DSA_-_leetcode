class Solution {
public:
    int subsets(int index, vector<int>& nums, unordered_map<int, int>& freq,
                int k) {
        if (index == nums.size()) {
            return 1;
        }
        int includeCurrent = 0;
        if (!freq[nums[index] - k] && !freq[nums[index] + k]) {
            freq[nums[index]]++;
            includeCurrent = subsets(index + 1, nums, freq, k);
            freq[nums[index]]--; // Backtrack
        }
        int excludeCurrent = subsets(index + 1, nums, freq, k);
        return includeCurrent + excludeCurrent;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        return subsets(0, nums, freq, k) - 1;
    } // Subtract 1 to exclude the empty subset
};