class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int solve(int num) {
        while (num >= 10) {
            num = digitSum(num);
        }
        return num;
    }

    int addDigits(int num) {
        return solve(num);
    }
};