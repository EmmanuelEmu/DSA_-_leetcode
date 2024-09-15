#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}
int fib(int n)
{
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

int main()
{

    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}