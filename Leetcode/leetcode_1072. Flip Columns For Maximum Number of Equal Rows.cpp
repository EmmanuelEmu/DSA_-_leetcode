#include <bits/stdc++.h>
using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;
    map<string, int> mp;

    for (auto row : matrix)
    {
        string pattern = "";
        for (auto i = 0; i < row.size(); i++)
        {
            if (row[0] == row[i])
            {
                pattern += '0';
            }
            else
            {
                pattern += '1';
            }
        }
        mp[pattern]++;
        count = max(count, mp[pattern]);
    }
    return count;
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
    cout << maxEqualRowsAfterFlips(matrix) << endl;
    return 0;
}