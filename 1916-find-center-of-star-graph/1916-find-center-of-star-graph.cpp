class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1; 
        vector<vector<int>> adj(n + 1);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int maxDegree = 0;
        int resultNode = -1;

        // Only check nodes from 1 to n (assuming 1-indexed)
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() > maxDegree) {
                maxDegree = adj[i].size();
                resultNode = i;
            }
        }

        return resultNode;
    }
};