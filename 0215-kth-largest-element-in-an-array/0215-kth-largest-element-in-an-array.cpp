class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }

        // map is internally sorted as always
        // sort(mp.begin(), mp.end());
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            k -= it->second;
            if (k <= 0) {
                return it->first;
            }
        }

        return -1;
    }
};