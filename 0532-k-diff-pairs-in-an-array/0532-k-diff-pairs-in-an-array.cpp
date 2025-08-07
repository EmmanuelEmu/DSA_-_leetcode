class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int arrSize = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        set<pair<int, int>> s;
        for (int i = 0; i < arrSize; i++) {
            int numToFind = k + nums[i];
            int start = i + 1;
            int end = arrSize - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (nums[mid] == numToFind) {
                    s.insert({nums[i], nums[mid]});
                    break;
                } else if (nums[mid] < numToFind) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return s.size();
    }
};