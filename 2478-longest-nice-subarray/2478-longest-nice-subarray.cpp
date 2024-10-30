class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxlen = 0;
        int left = 0, right = 0;
        int n = nums.size();
        int mask = 0;

        while (right < n) {
            if ((mask & nums[right]) != 0) { // Fixed parentheses
                mask ^= nums[left++];
            } else {
                mask |= nums[right++];
                maxlen = max(maxlen, right - left); // Also fix this line
            }
        }
        return maxlen;
    }
};