class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // int maxElement = *(max_element(nums.begin(), nums.end()));
        vector<int> hash(nums.size()+1, 0);
        for (auto it : nums) {
            hash[it]++;
        }
        vector<int> res;
        for (auto i = 1; i < hash.size(); i++) {
            if (hash[i] == 0 || hash[i] == 2) {
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};