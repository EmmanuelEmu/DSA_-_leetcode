class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefixSum[i] = sum;
        }
        int validSplitCount = 0;
        for (int i = 0; i < n - 1; i++) {
            long long leftSum = prefixSum[i];
            long long rightSum = sum - leftSum;
            if (leftSum >= rightSum) {
                validSplitCount++;
            }
        }
        return validSplitCount;
    }
};