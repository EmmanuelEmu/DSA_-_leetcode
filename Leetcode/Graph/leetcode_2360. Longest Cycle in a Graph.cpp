#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, int &count, int &cycleStart)
{
    vis[node] = 1;
    pathVis[node] = 1;
    count++;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis, count, cycleStart))
            {
                return true;
            }
        }
        else if (pathVis[it])
        {
            cycleStart = it;
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

int longestCycle(vector<int> &edges)
{
    int n = edges.size();
    int res = -1;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        if (edges[i] != -1)
        {
            adj[i].push_back(edges[i]);
        }
    }

    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int cycleStart = -1;

        if (!vis[i])
        {
            if (dfsCheck(i, adj, vis, pathVis, count, cycleStart))
            {
                // If a cycle is detected, calculate the actual cycle length
                int cycleLength = 0;
                if (cycleStart != -1)
                {
                    int curr = cycleStart;
                    do
                    {
                        cycleLength++;
                        curr = adj[curr][0]; // Move to the next node in the cycle
                    } while (curr != cycleStart);
                }

                // Update the longest cycle length
                res = max(res, cycleLength);
            }
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i];
    }
    cout << longestCycle(edges) << endl;
    return 0;
}