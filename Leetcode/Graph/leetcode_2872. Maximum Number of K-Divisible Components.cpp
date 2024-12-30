#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &values, int k, int &count)
{
    vis[node] = 1;
    long long sum = values[node];
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            sum += dfs(it, adj, vis, values, k, count);
        }
    }
    if (sum % k == 0)
    {
        count++;
        return 0;
    }
    return sum;
}

int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, values, k, count);
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    int k;
    cin >> k;
    cout << maxKDivisibleComponents(n, edges, values, k) << endl;
    return 0;
}