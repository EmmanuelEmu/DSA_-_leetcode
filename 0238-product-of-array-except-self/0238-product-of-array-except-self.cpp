class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);
        pref[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        for (auto i = 1; i < n; i++) {
            pref[i] = pref[i - 1] * nums[i];
        }
        for (auto i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i];
        }
        res[0] = suff[1];
        res[n - 1] = pref[n - 2];
        for (auto i = 1; i < n - 1; i++) {
            res[i] = pref[i - 1] * suff[i + 1];
        }
        return res;
    }
};