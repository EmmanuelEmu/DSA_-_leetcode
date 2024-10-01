class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (auto i = 0; i < board.size(); i++) {
            if (board[row][i] == c) {
                return false;
            }

            if (board[i][col] == c) {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (auto i = 0; i < 9; i++) {
            for (auto j = 0; j < 9; j++) {
                char current = board[i][j];
                if (current != '.') {
                    board[i][j] = '.';
                    if (!isValid(board, i, j, current)) {
                        return false;
                    }
                    board[i][j] = current;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) { return solve(board); }
};