class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool dfs(vector<vector<int>>& vis, vector<vector<char>>& board, string &word,
             int row, int col, int index) {
        
        if (index == word.size()) return true;

        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || vis[row][col] ||
            board[row][col] != word[index]) {
            return false;
        }

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (dfs(vis, board, word, nrow, ncol, index + 1))
                return true;
        }

        vis[row][col] = 0; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(vis, board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
