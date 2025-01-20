class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = arr.size();
        int rowSize = mat.size();
        int colSize = mat[0].size();

        map<int, pair<int, int>> matrixValue;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                matrixValue[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(rowSize, 0);
        vector<int> col(colSize, 0);

        for (int val = 0; val < n; val++) {
            auto it = matrixValue[arr[val]];
            row[it.first]++;
            col[it.second]++;
            if (row[it.first] == colSize || col[it.second] == rowSize) {
                return val;
            }
        }
        return -1;
    }
};