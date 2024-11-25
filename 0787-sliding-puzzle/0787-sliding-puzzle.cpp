class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Directions for movement
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        string target = "123450"; // Target board configuration

       
        string start;
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }

        // BFS setup
        unordered_set<string> visited; // Track visited states
        queue<string> queue;           // BFS queue
        queue.push(start);
        visited.insert(start);
        int steps = 0;

        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                string current = queue.front();
                queue.pop();
                if (current == target) {
                    return steps;
                }
                int zeroIndex = current.find('0');
                int zeroRow = zeroIndex / 3;
                int zeroCol = zeroIndex % 3;

                for (const auto& dir : dirs) {
                    int newRow = zeroRow + dir.first;
                    int newCol = zeroCol + dir.second;
                    if (newRow >= 0 && newRow < 2 && newCol >= 0 &&
                        newCol < 3) {
                        string newState = current;
                        int newIndex = newRow * 3 + newCol;
                        swap(newState[zeroIndex], newState[newIndex]);

                        if (!visited.count(newState)) {
                            queue.push(newState);
                            visited.insert(newState);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};