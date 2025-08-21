class Solution {
public:
    int findNthDigit(int n) {
        long long digitLength = 1, count = 9, start = 1;
        while (n > digitLength * count) {
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        start += (n - 1) / digitLength;
        string numStr = to_string(start);

        return (int)numStr[(n - 1) % digitLength] - '0';
    }
};