#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    // for the right move
    while (left <= right && top <= bottom)
    {
        for (auto i = left; i <= right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        top++;
        // for the bottom move
        for (auto i = top; i <= bottom; i++)
        {
            res.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (auto i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (auto i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
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
    vector<int> res = spiralOrder(matrix);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}