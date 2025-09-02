class Solution {
public:
    bool isSorted(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    void shiftIndex(vector<int>& nums, int index) {
        for (int i = index; i < nums.size() - 1; i++) {
            nums[i] = nums[i + 1];
        }
        nums.pop_back();
    }

    void minimumSumRemoval(vector<int>& nums) {
        int minIndex = -1;
        int minSum = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            int sum = nums[i] + nums[i - 1];
            if (sum < minSum) {
                minSum = sum;
                minIndex = i;
            }
        }
        nums[minIndex - 1] = minSum;
        shiftIndex(nums, minIndex);
    }

    int minimumPairRemoval(vector<int>& nums) {
        int minimumRemovals = 0;
        while (!isSorted(nums)) {
            minimumSumRemoval(nums);
            minimumRemovals++;
        }

        return minimumRemovals;
    }
};