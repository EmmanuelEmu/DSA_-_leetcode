#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj)
    {
        // Find the maximum vertex index in the graph
        int max = 0;
        for (auto &v : adj)
        {
            if (!v.empty())
            {
                int maxEl = *max_element(v.begin(), v.end());
                max = std::max(max, maxEl);
            }
        }
        vector<int> vis(max + 1, 0);
        vector<int> ans_bfs;
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            ans_bfs.push_back(vertex);
            for (auto v : adj[vertex])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans_bfs;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}