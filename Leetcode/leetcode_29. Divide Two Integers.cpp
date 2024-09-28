#include <bits/stdc++.h>
using namespace std;


// Minor fix handling the overflow case
int divide(int dividend, int divisor) {

    // Handle special case where overflow can occur
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // Overflow case
    }

    // Use long long to avoid overflow in abs and calculations
    long long div = abs((long long)dividend);
    long long temp = abs((long long)divisor);
    bool sign = (dividend < 0) == (divisor < 0); // Determine the sign

    long long ans = 0;
    while (div >= temp) {
        int cnt = 0;
        while (div >= (temp << (cnt + 1))) {
            cnt++;
        }
        ans += (1LL << cnt); // Use 1LL to ensure no overflow
        div -= (temp << cnt);
    }

    // Return based on the sign, ensure result fits within the int range
    return sign ? ans : -ans;
}


int main()
{
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor) << endl;
    return 0;
}