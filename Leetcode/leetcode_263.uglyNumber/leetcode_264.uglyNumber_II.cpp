#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;
    vector<int> dp(n);
    dp[0] = 1;
    for (auto i = 1; i < n; i++)
    {
        dp[i] = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        if (dp[i] == nextMultipleOf2)
        {
            i2++;
            nextMultipleOf2 = dp[i2] * 2;
        }
        if (dp[i] == nextMultipleOf3)
        {
            i3++;
            nextMultipleOf3 = dp[i3] * 3;
        }
        if (dp[i] == nextMultipleOf5)
        {
            i5++;
            nextMultipleOf5 = dp[i5] * 5;
        }
    }

    return dp[n - 1];
}

int main()
{

    return 0;
}