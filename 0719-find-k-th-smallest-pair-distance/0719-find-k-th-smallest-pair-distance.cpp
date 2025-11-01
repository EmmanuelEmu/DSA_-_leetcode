class Solution {
public:
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {
            while (nums[j] - nums[i] > mid)
                i++;
            count += j - i;
        }

        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};