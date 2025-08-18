class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> prefixSum(n + 1);
        int currSum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                currSum -= 1;
            } else {
                currSum += 1;
            }
            if (currSum == 0) {
                maxLen = i + 1;
            } else {
                if (mp.find(currSum) != mp.end()) {
                    maxLen = max(maxLen, i - mp[currSum]);
                } else {
                    mp[currSum] = i;
                }
            }
        }

        return maxLen;
    }
};