class Solution {
public:
    int answer = -1;

    void dfs(int node, vector<int>& edges, unordered_map<int, int>& dist,
             vector<int>& vis) {
        vis[node] = 1;
        int neighbour = edges[node];

        if (neighbour != -1) {
            if (!vis[neighbour]) {
                dist[neighbour] = dist[node] + 1;
                dfs(neighbour, edges, dist, vis);
            } else if (dist.find(neighbour) != dist.end()) {
                answer = max(answer, dist[node] - dist[neighbour] + 1);
            }
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_map<int, int> dist;
                dist[i] = 0;
                dfs(i, edges, dist, vis);
            }
        }
        return answer;
    }
};
