class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        cout << ans << endl;
        int count = 0;
        while (ans > 1) {
            int rem = ans % 2;
            if (rem == 1) {
                count++;
            }
            ans = ans / 2;
        }
        if(ans == 1) count++;
        return count;
    }
};