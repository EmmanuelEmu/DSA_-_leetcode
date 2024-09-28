class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n + 1, 1);
        // prime[0] = prime[1] = 0;
        for (int i = 0; i <= sqrt(n); i++) {
            if(i==0 || i==1) prime[i]=0;
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (prime[i]) {
                count++;
            }
        }
        return count;
    }
};