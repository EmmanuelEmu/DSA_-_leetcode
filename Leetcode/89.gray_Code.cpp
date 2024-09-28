#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n)
{
    vector<int> res;
    for (int i = 0; i < (1 << n); i++)
    {
        res.push_back(i ^ (i >> 1));
    }
    return res;
}

int main()
{

    int n;
    cin >> n;
    vector<int> result = grayCode(n);
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}