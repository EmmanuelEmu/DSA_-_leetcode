#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>> &matrix)
{
    long long sum = 0;
    int negativeCount = 0;
    int minAbsValue = INT_MAX;

    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += abs(matrix[i][j]);
            if (matrix[i][j] < 0)
                negativeCount++;
            minAbsValue = min(minAbsValue, abs(matrix[i][j]));
        }
    }
    if (negativeCount % 2 != 0)
    {
        sum -= 2 * minAbsValue;
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    for (auto i = 0; i < n; i++)
    {
        vector<int> row;
        for (auto j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            row.push_back(a);
        }
        matrix.push_back(row);
    }
    cout << maxMatrixSum(matrix) << endl;
    return 0;
}