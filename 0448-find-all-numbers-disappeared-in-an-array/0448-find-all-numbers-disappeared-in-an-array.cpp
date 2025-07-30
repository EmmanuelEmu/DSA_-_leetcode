class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int arrsize = nums.size();
        vector<int> res;
        map<int, int> mp;
        for (int i = 0; i < arrsize; i++) {
            mp[nums[i]]++;
        }
        for (int i = 1; i <= arrsize; i++) {
            if (mp[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};