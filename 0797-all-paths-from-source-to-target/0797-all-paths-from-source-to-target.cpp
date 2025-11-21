class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& currentPath,
             vector<vector<int>>& result, vector<bool>& visited) {
        currentPath.push_back(node);
        if (node == graph.size() - 1) {
            result.push_back(currentPath);
        } else {
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    dfs(neighbor, graph, currentPath, result, visited);
                    visited[neighbor] = false;
                }
            }
        }
        currentPath.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> currentPath;
        vector<bool> visited(graph.size(), false);
        dfs(0, graph, currentPath, result, visited);
        return result;
    }
};