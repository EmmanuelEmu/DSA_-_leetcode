#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (auto i = 0; i < n; i++)
    {
        for (auto j = i; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (auto i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    rotate(matrix);
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}