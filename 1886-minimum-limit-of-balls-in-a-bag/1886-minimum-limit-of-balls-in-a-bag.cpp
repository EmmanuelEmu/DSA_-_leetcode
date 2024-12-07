class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int maxOperations) {
        int totalOperations = 0;
        for (auto num : nums) {
            totalOperations +=
                (num + mid - 1) / mid - 1;
            if (totalOperations > maxOperations) {
                return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isPossible(nums, mid, maxOperations)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};