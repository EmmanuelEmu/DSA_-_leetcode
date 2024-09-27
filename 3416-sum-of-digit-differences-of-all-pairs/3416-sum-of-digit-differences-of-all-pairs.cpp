class Solution {
public:
    int getDigitPosition(int num, int position) {
        while (position > 0) {
            num = num / 10;
            position--;
        }
        return num % 10;
    }

    long long sumDigitDifferences(vector<int>& nums) {
        long long maxDigit = 0;
        long long totalSum = 0;
        long temp = nums[0];
        while (temp > 0) {
            temp = temp / 10;
            maxDigit++;
        }

        for (auto i = 0; i < maxDigit; i++) {
            vector<int> digit(10, 0);
            for (auto num : nums) {
                digit[getDigitPosition(num, i)]++;
            }
            int numNumber = nums.size();
            for (auto digitNumber = 0; digitNumber < 10; digitNumber++) {
                long long count = digit[digitNumber];
                totalSum += count * (numNumber - count);
            }
        }

        return totalSum/2;
    }
};