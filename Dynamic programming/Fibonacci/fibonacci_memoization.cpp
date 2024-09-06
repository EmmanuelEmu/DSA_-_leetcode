#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int> &dp)
{
    if (n<=1)
    {
        dp[n] = n;
        return n;
    }
    
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}

int main()
{

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibonacci(n, dp) << endl;
    
    for (auto it: dp)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}