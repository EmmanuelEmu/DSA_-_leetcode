#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> preSum;
NumMatrix(vector<vector<int>> &matrix)
{
    preSum.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
    for (auto i = 0; i <= matrix.size(); i++)
    {
        for (auto j = 0; j <= matrix[0].size(); j++)
        {
            preSum[i][j+1] = preSum[i][j] + matrix[i][j]; 
        }
    }
}

int sumRegion(int row1, int col1, int row2, int col2)
{
    int sum = 0;
    for (auto i = row1; i <= row2; i++)
    {
        sum += preSum[i][col2 + 1] - preSum[i][col1];
    }
    return sum;
}

int main()
{

    return 0;
}