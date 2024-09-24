#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    int row = n;
    int col = n;
    int val = 1;
    int left = 0, right = col - 1, top = 0, bottom = row - 1;
    vector<vector<int>> matrix(row, vector<int>(col));

    while (left <= right && top <= bottom)
    {
        for (auto i = left; i <= right; i++)
        {
            matrix[top][i] = val++;
        }
        top++;
        for (auto i = top; i <= bottom; i++)
        {
            matrix[i][right] = val++;
        }
        right--;
        if (top <= bottom)
        {
            for (auto i = right; i >= left; i--)
            {
                matrix[bottom][i] = val++;
            }
            bottom--;
        }
        if (left <= right)
        {
            for (auto i = bottom; i >= top; i--)
            {
                matrix[i][left] = val++;
            }
            left++;
        }
    }
    return matrix;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res = generateMatrix(n);
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}