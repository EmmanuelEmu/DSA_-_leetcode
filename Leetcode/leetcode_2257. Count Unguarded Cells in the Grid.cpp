#include <bits/stdc++.h>
using namespace std;

void visitGrid(int row, int col, vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    for (auto i = row + 1; i < m; i++)
    {
        if (grid[i][col] == 'W' || grid[i][col] == 'G')
        {
            break;
        }
        grid[i][col] = 'V';
    }
    for (auto i = row - 1; i >= 0; i--)
    {
        if (grid[i][col] == 'W' || grid[i][col] == 'G')
        {
            break;
        }
        grid[i][col] = 'V';
    }
    for(auto i=col+1; i<n; i++){
        if(grid[row][i] == 'W' || grid[row][i] == 'G'){
            break;
        }
        grid[row][i] = 'V';
    }
    for(auto i=col-1; i>=0; i--){
        if(grid[row][i] == 'W' || grid[row][i] == 'G'){
            break;
        }
        grid[row][i] = 'V';
    }
}

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    int count = 0;
    vector<vector<char>> grid(m, vector<char>(n, '.'));

    for (auto it : guards)
    {
        grid[it[0]][it[1]] = 'G';
    }

    for (auto it : walls)
    {
        grid[it[0]][it[1]] = 'W';
    }

    for (auto it : guards)
    {
        int row = it[0];
        int col = it[1];
        visitGrid(row, col, grid);
    }

    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    for(auto it : grid){
        for(auto i : it){
            if(i == '.'){
                count++;
            }
        }
    }

    return count;
}

int main()
{

    int m, n;
    cin >> m >> n;
    int g, w;
    cin >> g >> w;
    vector<vector<int>> guards, walls;
    while (g--)
    {
        int a, b;
        cin >> a >> b;
        guards.push_back({a, b});
    }
    while (w--)
    {
        int a, b;
        cin >> a >> b;
        walls.push_back({a, b});
    }
    cout << countUnguarded(m, n, guards, walls) << endl;
    return 0;
}