#include <bits/stdc++.h>
using namespace std;

int maximumPopulation(vector<vector<int>> &logs)
{
    int maxCount = -9999999;
    int candidate;
    for (int i = 0; i < logs.size(); i++)
    {
        int cnt = 0;
        for (auto j = 0; j < logs.size(); j++)
        {

            if ((logs[i][0] > logs[j][1]) || (logs[i][1] < logs[j][0]))
            {
                continue;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt > maxCount)
        {
            maxCount = cnt;
            candidate = logs[i][0];
        }
    }
    return candidate;
}

int main()
{

    vector<vector<int>> v;
    int n;
    cin >> n;
    while (n--)
    {
        int birth, death;
        cin >> birth >> death;
        vector<int> person = {birth, death};
        v.push_back(person);
    }

    int result = maximumPopulation(v);
    cout << result << endl;
    return 0;
}