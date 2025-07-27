class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        int trips = 0;
        int pairs = 0;

        map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            trips += pairs - freq[nums[i]] * (i - freq[nums[i]]);
            pairs += i - freq[nums[i]];
            freq[nums[i]]++;
        }

        return trips;
    }
};