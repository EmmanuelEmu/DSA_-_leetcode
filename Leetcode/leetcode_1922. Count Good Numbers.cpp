#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
long long powMod(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    
    long long ans = pow(a, b / 2);
    ans = (ans * ans) % MOD;

    if (b % 2 == 1)
    {
        ans = (ans * a) % MOD;
    }

    return ans;
}
int countGoodNumbers(long long n)
{
    long long even = (n + 1) / 2;
    long long odd = n / 2;

    long long evenComb = powMod(5, even) % MOD;
    long long oddComb = powMod(4, odd) % MOD;

    return static_cast<int>((evenComb * oddComb) % MOD);
}

int main()
{

    return 0;
}