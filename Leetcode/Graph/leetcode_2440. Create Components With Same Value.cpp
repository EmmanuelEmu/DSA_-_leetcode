#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &values, long long target, int &count)
{
    vis[node] = 1;
    long long sum = values[node];
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            sum += dfs(it, adj, vis, values, target, count);
        }
    }
    if (sum == target)
    {
        count++;
        return 0;
    }
    return sum;
}

int componentValue(vector<int> &nums, vector<vector<int>> &edges)
{
    int n = nums.size();
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
    int maxComponents = 0;

    for (int k = 1; k <= totalSum; k++)
    {
        if (totalSum % k == 0)
        {
            vector<int> vis(n, 0);
            int count = 0;
            if (dfs(0, adj, vis, nums, totalSum / k, count) == 0)
            {
                maxComponents = max(maxComponents, count);
            }
        }
    }
    return maxComponents - 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int e;
    cin >> e;

    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    cout << componentValue(nums, edges) << endl;
    return 0;
}