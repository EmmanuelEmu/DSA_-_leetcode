#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    int cnt = 0, bq = 0;

    for (auto fl : bloomDay)
    {
        if (fl <= day){
            cnt++;
        }
        else
        {
            bq += (cnt / k);
            cnt = 0;
        }
    }
    bq += (cnt / k);
    if (bq == m)
    {
        return true;
    }
    return false;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    if ((m*k) > bloomDay.size())
    {
        return -1;
    }
    auto minElement = min_element(bloomDay.begin(), bloomDay.end());
    int minDay = *minElement;

    auto maxElement = max_element(bloomDay.begin(), bloomDay.end());
    int maxDay = *maxElement;

    cout << minDay << " " << maxDay << endl;

    for (auto i = minDay; i <= maxDay; i++)    {

        // cout << possible(bloomDay, i, m, k) << endl;
        if (possible(bloomDay, i, m, k) == true)
        {
            return i;
        }
    }
    return -1;
}

int main()
{


    int n;
    vector<int> v;
    cin >> n;
    while (n--)
    {
        int day;
        cin >> day;
        v.push_back(day);
    }
    int m,k;
    cin >> m >> k;

    cout << minDays(v, m, k) << endl;
    return 0;
}