#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<vector<int>> &adj, int vis[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis))
            {
                return true;
            }
        }
        else if (pathVis[it])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<vector<int>> adj)
{
    // code here
    int vis[V] = {0};
    int pathVis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(i, adj, vis, pathVis))
            {
                return true;
            }
        }
    }
    return false;

}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << isCyclic(V, adj) << endl;
    return 0;
}