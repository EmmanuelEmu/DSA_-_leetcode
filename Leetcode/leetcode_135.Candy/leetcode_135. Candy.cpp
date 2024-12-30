#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> leftCal(n, 1);
    leftCal[0] = 1;
    for (auto i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            leftCal[i] = leftCal[i - 1] + 1;
        }
        else
        {
            leftCal[i] = 1;
        }
    }
    int sum = 0, cur = 1, right = 1;
    sum += max(cur, leftCal[n - 1]);
    for (auto i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            cur += right;
            right = cur;
        }
        else
        {
            cur = 1;
            right = 1;
        }
        sum += max(cur, leftCal[i]);
    }

    return sum;
}

int main()
{

    return 0;
}