class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis,
                  vector<int>& pathVis, vector<int> &check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, graph, vis, pathVis, check)) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }

        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n,0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};