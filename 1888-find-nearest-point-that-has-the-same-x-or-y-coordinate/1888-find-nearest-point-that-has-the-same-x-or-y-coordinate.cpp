class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<pair<int, int>> smallestDistancePoints; // {distance, index}

        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                smallestDistancePoints.push_back({dist, i});
            }
        }

        if (smallestDistancePoints.empty())
            return -1;

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        };

        sort(smallestDistancePoints.begin(), smallestDistancePoints.end(), cmp);

        return smallestDistancePoints[0].second;
    }
};