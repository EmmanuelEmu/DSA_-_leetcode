class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int n = nums.size();
        int count = 0;
        vector<int> ans;
        int i = 0, j = 1;
        int numCount = 1;
        while (j < n) {
            if (nums[i] == nums[j]) {
                numCount++;
                if (numCount > 2) {
                    nums[j] = INT_MAX;
                }
            } else {
                i = j;
                numCount = 1;
            }
            j++;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != INT_MAX) {
                count++;
                ans.push_back(nums[i]);
            }
        }
        nums = ans;
        return count;
    }
};