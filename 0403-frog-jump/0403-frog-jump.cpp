class Solution {
public:
    bool solve(int ind, int k, vector<int>& stones, vector<vector<bool>>& dp,
               vector<vector<bool>>& visited) {
        if (ind == stones.size() - 1) {
            return true;
        }

        if (visited[ind][k]) {
            return dp[ind][k];
        }

        visited[ind][k] = true;

        int jumpPlus = stones[ind] + k + 1;
        int jumpMinus = stones[ind] + k - 1;
        int notJump = stones[ind] + k;

        // Find the next stone using lower_bound for exact matching
        auto jumpStoneIt = lower_bound(stones.begin(), stones.end(), jumpPlus);
        auto jumpMinusStoneIt =
            lower_bound(stones.begin(), stones.end(), jumpMinus);
        auto notJumpStoneIt =
            lower_bound(stones.begin(), stones.end(), notJump);

        // Determine the valid indices for each jump
        int jumpStone =
            (jumpStoneIt != stones.end() && *jumpStoneIt == jumpPlus)
                ? jumpStoneIt - stones.begin()
                : -1;
        int jumpMinusStone = (jumpMinusStoneIt != stones.end() &&
                              *jumpMinusStoneIt == jumpMinus && k - 1 > 0)
                                 ? jumpMinusStoneIt - stones.begin()
                                 : -1;
        int notJumpStone =
            (notJumpStoneIt != stones.end() && *notJumpStoneIt == notJump)
                ? notJumpStoneIt - stones.begin()
                : -1;

        // Try the jumps recursively
        bool jump = (jumpStone != -1)
                        ? solve(jumpStone, k + 1, stones, dp, visited)
                        : false;
        bool jumpBack = (jumpMinusStone != -1)
                            ? solve(jumpMinusStone, k - 1, stones, dp, visited)
                            : false;
        bool noJump = (notJumpStone != -1)
                          ? solve(notJumpStone, k, stones, dp, visited)
                          : false;

        return dp[ind][k] = jump || jumpBack || noJump;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        return solve(0, 0, stones, dp, visited);
    }
};