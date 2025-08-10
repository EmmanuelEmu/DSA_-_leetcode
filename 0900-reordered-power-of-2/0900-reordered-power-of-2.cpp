class Solution {
public:
    int myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            if (n > 0) {
                return half * half * x;
            } else {
                return (half * half) / x;
            }
        }
    }

    bool reorderedPowerOf2(int n) {
        vector<int> numDigits(10, 0);
        while (n) {
            numDigits[n % 10]++;
            n /= 10;
        }
        for (int i = 0; i < 31; i++) {
            vector<int> powOf2(10, 0);
            int powVal = myPow(2, i);
            while (powVal) {
                powOf2[powVal % 10]++;
                powVal /= 10;
            }
            if (powOf2 == numDigits)
                return true;
        }
        return false;
    }
};