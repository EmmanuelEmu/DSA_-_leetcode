class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int whiteCount = 0;
        int minRecolors = INT_MAX;
        int l = 0, r = 0;
        while (r < n) {
            if (blocks[r] == 'W') {
                whiteCount++;
            }
            if (r - l + 1 > k) {
                if (blocks[l] == 'W') {
                    whiteCount--;
                }
                l++;
            }

            if (r - l + 1 == k) {
                minRecolors = min(minRecolors, whiteCount);
            }
            r++;
        }
        return minRecolors;
    }
};