class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negativeCount = 0;
        int minAbsValue = INT_MAX;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    negativeCount++;
                minAbsValue = min(minAbsValue, abs(matrix[i][j]));
            }
        }
        if (negativeCount % 2 != 0) {
            sum -= 2 * minAbsValue;
        }

        return sum;
    }
};