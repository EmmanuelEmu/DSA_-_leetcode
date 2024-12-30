#include <bits/stdc++.h>
using namespace std;

int countLessEqual(const vector<vector<int>> &matrix, int value)
{
    int count = 0;
    int n = matrix.size();
    int row = n - 1;
    int col = 0;

    // Start from the bottom-left corner and count elements <= value
    while (row >= 0 && col < n)
    {
        if (matrix[row][col] <= value)
        {
            count += (row + 1);
            col++;
        }
        else
        {
            row--;
        }
    }
    return count;
}

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    int answer = left;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int count = countLessEqual(matrix, mid);

        if (count < k)
        {
            left = mid + 1;
        }
        else
        {
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}

int findKthNumber(int m, int n, int k)
{
    vector<vector<int>> numbers;
    for (auto i = 1; i <= m; i++)
    {
        vector<int> temp;
        for (auto j = 1; j <= n; j++)
        {
            temp.push_back(i * j);
        }
        numbers.push_back(temp);
    }
    return kthSmallest(numbers, k);
}

int main()
{

    return 0;
}