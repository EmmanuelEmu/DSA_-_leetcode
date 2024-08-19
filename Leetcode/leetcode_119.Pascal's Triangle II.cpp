#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int>row;

    if (rowIndex==0)
    {
        row.push_back(1);
        return row;
    }
    vector<int> result = getRow(rowIndex-1);
    row.push_back(1);
    for (auto i = 0; i < result.size()-1; i++)
    {
        row.push_back(result[i]+result[i+1]);
    }
    row.push_back(1);
    return row;
}

int main()
{

    int n;
    cin >> n;
    vector<int> result = getRow(n);
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}