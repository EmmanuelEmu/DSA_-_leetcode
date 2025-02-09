class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> freq;
        long long n = nums.size();
        long long goodPairs = 0;

        long long totalPairs = n * (n - 1) / 2;
        for (auto i = 0; i < n; i++) {
            goodPairs += freq[i - nums[i]];
            freq[i - nums[i]]++;
        }

        return totalPairs - goodPairs;
    }
};
