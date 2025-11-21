class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>>
            numberedPoints; // {pointNumber, {x, y}}
        int pointNumber = 0;
        for (auto point : points) {
            numberedPoints.push_back({pointNumber++, {point[0], point[1]}});
        }
        int n = numberedPoints.size();
        vector<vector<pair<int, int>>> adj(n+1); // {pointMap, {point1, point2}}

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(numberedPoints[i].second.first -
                               numberedPoints[j].second.first) +
                           abs(numberedPoints[i].second.second -
                               numberedPoints[j].second.second);
                adj[numberedPoints[i].first].push_back(
                    {dist, numberedPoints[j].first});
                adj[numberedPoints[j].first].push_back(
                    {dist, numberedPoints[i].first});
            }
        }

        // for(auto edg : adj[0]){
        //     cout << "Dist : " << edg.first << " " << "Node from : " << edg.second << endl;
        // }

        vector<int> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq; // {cost, node}}
        // FIX 1: Start from node 0
        pq.push({0, 0});

        int totalCost = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr.first;
            int node = curr.second;
            if (visited[node]) {
                continue;
            }
            visited[node] = true;
            totalCost += cost;
            for (auto edge : adj[node]) {
                if (!visited[edge.second]) {
                    pq.push(edge);
                }
            }
        }
        return totalCost;
    }
};