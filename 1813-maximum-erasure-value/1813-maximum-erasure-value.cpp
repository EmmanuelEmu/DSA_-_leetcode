class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        int maxSum = 0, l = 0, r = 0, currentSum = 0;

        while (r < n) {
            if (mp.find(nums[r]) == mp.end()) {
                mp[nums[r]] = r;
                currentSum += nums[r];
                maxSum = max(maxSum, currentSum);
            } else {
                while (l <= mp[nums[r]]) {
                    currentSum -= nums[l];
                    mp.erase(nums[l]);
                    l++;
                }
                mp[nums[r]] = r;
                currentSum += nums[r];
                maxSum = max(maxSum, currentSum);
            }
            r++;
        }
        return maxSum;
    }
};