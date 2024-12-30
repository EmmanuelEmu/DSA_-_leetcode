#include <bits/stdc++.h>
using namespace std;


vector<int> dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &ans)
{
    ans.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, ans);
        }
    }
    return ans;
}

vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
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
    vector<int> ans;
    dfs(0, vis, adj, ans);
    return ans;
}

int main()
{

    return 0;
}