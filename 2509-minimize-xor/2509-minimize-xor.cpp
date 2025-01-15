class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsCount = 0;
        while (num2 > 0) {
            num2 = num2 & (num2 - 1);
            setBitsCount++;
        }
        bitset<32> binary(num1);
        bitset<32> temp;
        for (int i = 31; i >= 0 && setBitsCount > 0; i--) {
            if (binary[i] == 1) {
                temp[i] = 1;
                setBitsCount--;
            }
        }
        for (int i = 0; i < 32 && setBitsCount > 0; i++) {
            if (temp[i] == 0) {
                temp[i] = 1;
                setBitsCount--;
            }
        }
        return static_cast<int>(temp.to_ulong());
    }
};