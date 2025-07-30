class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for (auto i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (auto i = n - 1; i > 0; i--) {
                if (nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
            reverse(nums.begin() + ind + 1, nums.end());
        }
        return nums;
    }

    int nextGreaterElement(int n) {
        vector<int> nums;
        int temp = n;
        while (n > 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());
        vector<int> ans = nextPermutation(nums);
        long long res = 0;
        for (int i = 0; i < ans.size(); i++) {
            res = res * 10 + ans[i];
        }
        if (res <= temp || res < INT32_MIN || res > INT32_MAX)
            return -1;
        return (int)res;
    }
};