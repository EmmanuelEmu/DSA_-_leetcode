class Solution {
public:
    int divide(int dividend, int divisor) {

        // Handle special case where overflow can occur
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case
        }

        long long div = abs((long long)dividend);
        long long temp = abs((long long)divisor);
        bool sign = (dividend < 0) == (divisor < 0);

        long long ans = 0;
        while (div >= temp) {
            int cnt = 0;
            while (div >= (temp << (cnt + 1))) {
                cnt++;
            }
            ans += (1LL << cnt);
            div -= (temp << cnt);
        }

        return sign ? ans : -ans;
    }
};