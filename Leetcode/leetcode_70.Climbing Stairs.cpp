#include <bits/stdc++.h>
using namespace std;
/*
Uing simple recursion and backtracking

int comb(int n, int &count, int sum){
    if (sum == n || sum>n)
    {
        count++;
        return count;
    }
    comb(n, count, sum+1);
    comb(n, count, sum+2);

    return count;
}


int climbStairs(int n)
{
    int count = 0;
    return comb(n, count, 0);
}
*/



// Using recurision, backtracking and memiozation
int DP(int n, vector<int> &dp)
{
    if (n <= 2)
    {
        dp[n] = n;
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = DP(n - 1, dp) + DP(n - 2, dp);
    return dp[n];
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return DP(n, dp);
}

int main()
{

    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}