#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> ans_bfs)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;

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

vector<vector<int>> connectedcomponents(int v, vector<vector<int>> &edges)
{
    vector<int> vis(v, 0);
    vector<vector<int>> adj(v + 1);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<vector<int>> ans;
    vector<int> temp;
    for (auto i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            temp = bfsOfGraph(i, vis, adj, temp);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            temp.clear();
        }
    }
    return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (auto i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    vector<vector<int>> ans = connectedcomponents(v, edges);
    for (auto v : ans)
    {
        for (auto val : v)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}