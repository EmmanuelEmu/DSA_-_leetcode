class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int posInd = 0, negInd = 1;
        for (auto i = 0; i < n; i++) {
            if (nums[i] < 0) {
                res[negInd] = nums[i];
                negInd += 2;
            } else {
                res[posInd] = nums[i];
                posInd += 2;
            }
        }
        return res;
    }
};