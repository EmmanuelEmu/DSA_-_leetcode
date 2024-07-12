#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    vector<pair<int, int>> result_index;
    for (auto i = 0; i < matrix.size(); i++)
    {
        for (auto j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                result_index.push_back(make_pair(i, j));
            }
        }
    }

    for (auto i = 0; i < result_index.size(); i++)
    {
        // cout << "row: " << result_index[i].first << " column: " << result_index[i].second << endl;
        for (auto j = 0; j < matrix[result_index[i].first].size(); j++)
        {
            matrix[result_index[i].first][j] = 0;
        }

        for (auto k = 0; k < matrix.size(); k++)
        {
            matrix[k][result_index[i].second] = 0;
        }
    }

    for (auto i = 0; i < matrix.size(); i++)
    {
        for (auto j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    setZeroes(arr);

    return 0;
}