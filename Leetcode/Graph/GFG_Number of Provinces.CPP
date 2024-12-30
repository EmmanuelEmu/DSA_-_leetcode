#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    vector<int> vis(V, 0);
    int count = 0;
    vector<vector<int>> adjec(V);
    for (auto i = 0; i < V; i++)
    {
        for (auto j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjec[i].push_back(j);
                adjec[j].push_back(i);
            }
        }
    }

    for (auto i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            bfs(i, vis, adjec);
            count++;
        }
    }
    return count;
}

int main()
{

    return 0;
}