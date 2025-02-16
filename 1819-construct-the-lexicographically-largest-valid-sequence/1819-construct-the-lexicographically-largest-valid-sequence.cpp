class Solution {
public:
    bool generateSequence(vector<int>& seq, vector<bool>& visited, int pos,
                          int n) {
        if (pos == 2 * n - 1) {
            return true;
        }
        if (seq[pos] != -1) {
            return generateSequence(seq, visited, pos + 1, n);
        }
        for (int i = n; i >= 1; i--) {
            int nextPos = (i == 1) ? pos : pos + i;
            if (visited[i] ||
                (i > 1 && (nextPos >= 2 * n - 1 || seq[nextPos] != -1))) {
                continue;
            }
            visited[i] = true;
            seq[pos] = seq[nextPos] = i;
            if (generateSequence(seq, visited, pos + 1, n)) {
                return true;
            }
            visited[i] = false;
            seq[pos] = seq[nextPos] = -1;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        int m = 2 * n - 1;
        vector<int> seq(2 * n - 1, -1);
        vector<bool> visited(n + 1, false);
        generateSequence(seq, visited, 0, n);
        return seq;
    }
};