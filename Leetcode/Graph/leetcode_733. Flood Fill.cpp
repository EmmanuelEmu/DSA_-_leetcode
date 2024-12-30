#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>> &image, vector<vector<int>> &vis, int color, int iniPixel)
{
    if (row < 0 || col < 0 || row >= n || col >= m || vis[row][col] || image[row][col] != iniPixel)
    {
        return;
    }
    vis[row][col] = 1;
    image[row][col] = color;
    dfs(row + 1, col, n, m, image, vis, color, iniPixel);
    dfs(row - 1, col, n, m, image, vis, color, iniPixel);
    dfs(row, col + 1, n, m, image, vis, color, iniPixel);
    dfs(row, col - 1, n, m, image, vis, color, iniPixel);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> tempImage = image;
    int iniPixel = image[sr][sc];
    dfs(sr, sc, n, m, tempImage, vis, color, iniPixel);
    return tempImage;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> image;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            row.push_back(val);
        }
        image.push_back(row);
    }
    int sr, sc, color;
    cin >> sr >> sc >> color;
    vector<vector<int>> ans = floodFill(image, sr, sc, color);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}