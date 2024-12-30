#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto i = 1; i <= n; i++)
    {
        for (auto val : adj[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}