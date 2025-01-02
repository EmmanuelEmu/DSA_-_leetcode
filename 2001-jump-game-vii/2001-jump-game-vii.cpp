class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') {
            return false;
        }

        vector<bool> reachable(n, false);
        reachable[0] = true;

        int reachableCount = 0;

        for (int i = 1; i < n; i++) {
            if (i >= minJump) {
                reachableCount += reachable[i - minJump];
            }
            if (i > maxJump) {
                reachableCount -= reachable[i - maxJump - 1];
            }

            if (reachableCount > 0 && s[i] == '0') {
                reachable[i] = true;
            }
        }

        return reachable[n - 1];
    }
};