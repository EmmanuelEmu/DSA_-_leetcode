#include<bits/stdc++.h>
using namespace std;


int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}