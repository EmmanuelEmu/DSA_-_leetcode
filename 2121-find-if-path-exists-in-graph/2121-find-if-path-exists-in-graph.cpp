class Solution {
public:
    bool dfs(int nodes, int source, int destination, vector<bool>& visited,
             vector<vector<int>>& adj) {
        if (source == destination)
            return true;
        visited[source] = true;
        for (auto& neighbor : adj[source]) {
            if (!visited[neighbor]) {
                if (dfs(nodes, neighbor, destination, visited, adj))
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                if (dfs(n, source, destination, visited, adj))
                    return true;
            }
        }
        return false;
    }
};