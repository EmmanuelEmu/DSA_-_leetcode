class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0;
        int maxLen = 0;
        int cnt = 0;
        while (r < nums.size()) {
            if (nums[r] == 1) {
                cnt++;
                maxLen = max(maxLen, cnt);
            } else {
                l = r;
                cnt = 0;
            }
            r++;
        }
        return maxLen;
    }
};