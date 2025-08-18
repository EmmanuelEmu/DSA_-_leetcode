class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<pair<pair<int, int>, int>> numTodigitVec;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            numTodigitVec.push_back({{nums[i], digitSum(nums[i])}, i});
        }
        sort(numTodigitVec.begin(), numTodigitVec.end(),
             [](const auto& a, const auto& b) {
                 if (a.first.second == b.first.second) {
                     return a.first.first <
                            b.first.first; // smaller number first
                 }
                 return a.first.second < b.first.second; // primary: digitSum
             });

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (numTodigitVec[i].second == i) {
                continue;
            } else {
                swaps++;
                swap(numTodigitVec[i], numTodigitVec[numTodigitVec[i].second]);
                i--;
            }
        }
        return swaps;
    }
};