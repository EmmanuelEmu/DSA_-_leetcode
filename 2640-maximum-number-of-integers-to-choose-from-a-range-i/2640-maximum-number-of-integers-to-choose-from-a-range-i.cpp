class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int maxEl = *max_element(banned.begin(), banned.end());
        int count = 0;
        int range = maxEl > n ? maxEl : n;
        vector<int> hash(range + 1, 0);
        for (auto num : banned) {
            hash[num]++;
        }
        int sum = 0;
        for (auto i = 1; i <= n; i++) {
            if (hash[i] == 0) {
                sum += i;
                if (sum <= maxSum) {
                    count++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};