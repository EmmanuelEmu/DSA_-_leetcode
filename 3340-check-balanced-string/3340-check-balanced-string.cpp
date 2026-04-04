class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size();
        int oddSum = 0;
        int evenSum = 0;
        for (auto i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenSum += num[i] - '0';
            } else {
                oddSum += num[i] - '0';
            }
        }

        return (oddSum == evenSum) ? true : false;
    }
};