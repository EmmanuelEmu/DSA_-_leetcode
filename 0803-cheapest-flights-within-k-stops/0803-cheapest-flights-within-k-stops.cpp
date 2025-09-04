class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // storing {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k)
                continue;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int adjCost = it.second;
                if (cost + adjCost < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + adjCost;
                    q.push({stops + 1, {adjNode, cost + adjCost}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};