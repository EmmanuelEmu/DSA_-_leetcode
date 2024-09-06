#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    int cnt = 0, bq = 0;

    for (auto fl : bloomDay)
    {
        if (fl <= day)
        {
            cnt++;
        }
        else
        {
            bq += (cnt / k);
            cnt = 0;
        }
    }
    bq += (cnt / k);
    if (bq >= m)
    {
        return true;
    }
    return false;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    long long int mul = (long long)m * (long long)k;
    if (mul > bloomDay.size())
    {
        return -1;
    }
    auto minElement = min_element(bloomDay.begin(), bloomDay.end());
    int minDay = *minElement;

    auto maxElement = max_element(bloomDay.begin(), bloomDay.end());
    int maxDay = *maxElement;

    // cout << minDay << " " << maxDay << endl;

    int res = -1;
    while (minDay <= maxDay)
    {
        int midDay = minDay + (maxDay - minDay) / 2;

        if (!possible(bloomDay, midDay, m, k))
        {
            minDay = midDay + 1;
        }
        else
        {
            res = midDay;
            maxDay = midDay - 1;
        }
    }

    return res;
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
    int m, k;
    cin >> m >> k;

    cout << minDays(v, m, k) << endl;
    return 0;
}