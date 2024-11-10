class Solution {
public:
    void addContributionToR(int val, vector<int>& bitArray, bool isAdd) {
        int i = 0;
        while (val > 0 && i < bitArray.size()) {
            bitArray[i] += (isAdd ? 1 : -1) * (val & 1);
            i++;
            val >>= 1;
        }
    }

    bool isContributionIsEqualToK(vector<int>& bitArray, int k) {
        int bitVectorValue = 0;
        for (int i = 0; i < bitArray.size(); i++) {
            if (bitArray[i]) {
                bitVectorValue += (1 << i);
            }
        }
        return bitVectorValue >= k;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minlen = INT_MAX;
        vector<int> bitArray(32, 0);
        int i = 0, j = 0;
        while (j < n) {
            addContributionToR(nums[j], bitArray, true);
            while (isContributionIsEqualToK(bitArray, k) && i<=j) {
                minlen = min(minlen, j - i + 1);
                addContributionToR(nums[i], bitArray, false);
                i++;
            }
            j++;
        }
        return minlen == INT_MAX ? -1 : minlen;
    }
};