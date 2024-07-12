#include <bits/stdc++.h>
using namespace std;


vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> temp;
    temp.push_back(1);
    for (auto i = 1; i < row; i++)
    {
        ans = ans*(row-i);
        ans = ans/i;
        temp.push_back(ans);
    }

    return temp;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    for (auto i = 1; i <= numRows; i++)
    {
        vector<int> singleRow = generateRow(i);
        result.push_back(singleRow);
    }   

    return result;
}

int main()
{
    int row;
    cin >> row;
    vector<vector<int>> result = generate(row);

    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
