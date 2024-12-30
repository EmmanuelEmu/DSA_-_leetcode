#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
{
    int n = box.size();
    int m = box[0].size();


    for (auto &row : box) 
    {
        int positionOfStone = m - 1;
        for (int i = m - 1; i >= 0; i--)
        {
            if (row[i] == '#')
            {
                swap(row[i], row[positionOfStone]);
                positionOfStone--;
            }
            else if (row[i] == '*')
            {
                positionOfStone = i - 1;
            }
        }
    }
    vector<vector<char>> res(m, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[j][n - 1 - i] = box[i][j];
        }
    }
    return res;
}

int main()
{
    vector<vector<char>> box = {{'#', '.', '#'}};
    vector<vector<char>> result = rotateTheBox(box);

    // Print the result
    for (const auto &row : result)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
