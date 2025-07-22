class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int arrsize = nums.size();
        int product = 1;
        int count = 0;
        int left = 0;

        for (int right = 0; right < arrsize; right++) {
            product *= nums[right];
            while (product >= k && left <= right) {
                product /= nums[left];
                left++;
            }
            count += (right - left + 1);
        }

        return count;
    }
};