class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(
            cmp);

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = x * x + y * y;
            minHeap.push({dist, x, y});
        }

        vector<vector<int>> result;
        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            result.push_back({top[1], top[2]});
        }

        return result;
    }
};