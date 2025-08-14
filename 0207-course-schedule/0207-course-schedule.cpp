class Solution {
public:
    bool isCycledfs(int node, vector<vector<int>>& adj, vector<int>& vis,
                    vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (isCycledfs(it, adj, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        bool isCycle = false;
        for (int it = 0; it < numCourses; it++) {
            if (!vis[it]) {
                if (isCycledfs(it, adj, vis, pathVis)) {
                    isCycle = true;
                    break;
                }
            }
        }
        if (isCycle) {
            return false;
        } else {
            return true;
        }
    }
};