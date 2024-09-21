class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> preSumMap;
        int sum = 0;
        int res = 0;
        preSumMap[0] = 1;
        for (auto i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                res += preSumMap[rem];
            }
            preSumMap[sum]++;
        }
        return res;
    }
};