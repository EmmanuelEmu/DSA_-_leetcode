class Solution {
public:

// This got time limit error
    void rotate(vector<int>& nums, int k) {
        for (auto i = 0; i < k; i++) {
            int lastElement = nums[nums.size() - 1];
            nums.pop_back();
            nums.insert(nums.begin(), lastElement);
        }
    }
};