class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                if (temp.size() == 3) {
                    return true;
                }
            } else {
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return false;
    }
};