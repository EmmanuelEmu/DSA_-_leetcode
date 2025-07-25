class Solution {
public:
    long long getnCk(long long n, long long k, vector<vector<long long>>& memo) {

        if (k > n)
            return 0;
        if (k == 0 || k == n)
            return 1;
        if (memo[n][k] != -1)
            return memo[n][k];
        return memo[n][k] = getnCk(n - 1, k - 1, memo) + getnCk(n - 1, k, memo);
    }

    int numTrees(int n) {
        vector<vector<long long>> memo(2*n + 1, vector<long long>(n + 1, -1));
        return (int)(getnCk(2 * n, n, memo) / (n + 1));
    }
};