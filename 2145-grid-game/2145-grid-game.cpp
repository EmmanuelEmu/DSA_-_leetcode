class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottomSum = 0;
        long long result = LLONG_MAX;
        for (int j = 0; j < n; j++) {
            topSum -= grid[0][j];
            long long secondRobot = max(topSum, bottomSum);
            result = min(result, secondRobot);
            bottomSum += grid[1][j];
        }
        return result;
    }
};