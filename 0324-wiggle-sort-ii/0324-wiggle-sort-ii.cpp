class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        int lastIndex = n - 1;
        for (auto i = 1; i < n; i += 2) {
            nums[i] = sortedNums[lastIndex--];
        }
        for (auto i = 0; i < n; i += 2) {
            nums[i] = sortedNums[lastIndex--];
        }
        for (auto it : nums) {
            cout << it << " ";
        }
    }
};