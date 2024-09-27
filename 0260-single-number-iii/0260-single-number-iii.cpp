class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        for (auto it : nums) {
            xorr ^= it;
        }
        int rightMost = (xorr & xorr - 1) ^ xorr;
        int leftBucket = 0, rightBucket = 0;
        for (auto it : nums) {
            if (it & rightMost) {
                leftBucket ^= it;
            } else {
                rightBucket ^= it;
            }
        }
        return {leftBucket, rightBucket};
    }
};