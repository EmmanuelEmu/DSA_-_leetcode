class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<int>>& image,
             vector<vector<int>>& vis, int color, int iniPixel) {
        if (row < 0 || col < 0 || row >= n || col >= m || vis[row][col] ||
            image[row][col] != iniPixel) {
            return;
        }
        vis[row][col] = 1;
        image[row][col] = color;
        dfs(row + 1, col, n, m, image, vis, color, iniPixel);
        dfs(row - 1, col, n, m, image, vis, color, iniPixel);
        dfs(row, col + 1, n, m, image, vis, color, iniPixel);
        dfs(row, col - 1, n, m, image, vis, color, iniPixel);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> tempImage = image;
        int iniPixel = image[sr][sc];
        dfs(sr, sc, n, m, tempImage, vis, color, iniPixel);
        return tempImage;
    }
};