class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int k = n - 2; k >= 2; k--) {
            unordered_map<int, int> freq;

            for (int l = k + 1; l < n; l++) {
                freq[nums[l]]++;
            }

            for (int i = 0; i < k - 1; i++) {
                for (int j = i + 1; j < k; j++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (freq.find(sum) != freq.end()) {
                        count += freq[sum];
                    }
                }
            }
        }

        return count;
    }
};