#include<bits/stdc++.h>
using namespace std;


int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n+1];
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    for (auto i = 1; i <= n; i++)
    {
        for (auto val : adj[i])
        {
            cout << val.first << " " << val.second << endl;
        }
    }
    
    return 0;
}