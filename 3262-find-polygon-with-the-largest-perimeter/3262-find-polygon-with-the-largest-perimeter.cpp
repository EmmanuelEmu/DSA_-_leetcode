class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long maxi = INT_MIN;
        sum += nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (sum > nums[i]) {
                sum += nums[i];
                maxi = max(maxi, sum);
            } else {
                sum += nums[i];
            }
        }
        if (maxi == INT_MIN) {
            return -1;
        }
        return maxi;
    }
};