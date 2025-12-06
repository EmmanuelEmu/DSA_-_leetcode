class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        // factors.push_back(1);
        // factors.push_back(n);
        for (auto i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (n / i != i)
                    factors.push_back(n / i);
            }
        }
        sort(factors.begin(), factors.end());
        for (auto it : factors)
            cout << it << " ";
        cout << endl;
        return factors.size() >= k ? factors[k - 1] : -1;
    }
};