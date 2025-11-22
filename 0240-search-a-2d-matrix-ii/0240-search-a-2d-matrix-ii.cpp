class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        long long rowNumber = 0;
        for (const auto &singleRow : matrix) {
            long long lb = 0;
            long long ub = singleRow.size() - 1;
            if ((int)matrix[rowNumber][lb] <= target &&
                (int)matrix[rowNumber][ub] >= target) {
                while (lb <= ub) {
                    long long mid = lb + (ub - lb) / 2;
                    if((int)matrix[rowNumber][mid] == target) return true;
                    else if((int)matrix[rowNumber][mid] < target){
                        lb = mid+1;
                    } else{
                        ub = mid-1;
                    }
                }
            }
            rowNumber++;
        }

        return false;
    }
};