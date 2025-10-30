class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> sortedIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            sortedIntervals.push_back({intervals[i][0], i});
        }
        sort(sortedIntervals.begin(), sortedIntervals.end());
        vector<int> result(n, -1);
        for (auto i = 0; i < n; i++) {
            int end = intervals[i][1];
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sortedIntervals[mid][0] >= end) {
                    result[i] = sortedIntervals[mid][1];
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return result;
    }
};