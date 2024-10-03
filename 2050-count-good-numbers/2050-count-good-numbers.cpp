class Solution {
public:
    const long long MOD = 1000000007;
    long long powMod(long long a, long long b) {
        if (b == 0) {
            return 1;
        }

        a = a % MOD;
        long long ans = powMod(a, b / 2);
        if (b % 2 == 0) {
            return (ans * ans) % MOD;
        }
        return (ans * ans * a) % MOD;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenComb = powMod(5, even) % MOD;
        long long oddComb = powMod(4, odd) % MOD;

        return static_cast<int>((evenComb * oddComb) % MOD);
    }
};