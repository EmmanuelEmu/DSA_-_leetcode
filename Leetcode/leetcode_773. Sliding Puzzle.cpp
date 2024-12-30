#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

int slidingPuzzle(vector<vector<int>> &board)
{
    // Directions for movement
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    string target = "123450"; // Target board configuration

    // Convert the board into a string
    string start;
    for (const auto &row : board)
    {
        for (int num : row)
        {
            start += to_string(num);
        }
    }

    // BFS setup
    unordered_set<string> visited; // Track visited states
    queue<string> queue;           // BFS queue
    queue.push(start);
    visited.insert(start);
    int steps = 0;

    while (!queue.empty())
    {
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            string current = queue.front();
            queue.pop();
            if (current == target)
            {
                return steps;
            }

            // Find the position of '0'
            int zeroIndex = current.find('0');
            int zeroRow = zeroIndex / 3;
            int zeroCol = zeroIndex % 3;

            // Try all possible movements of the blank space
            for (const auto &dir : dirs)
            {
                int newRow = zeroRow + dir.first;
                int newCol = zeroCol + dir.second;
                if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3)
                {
                    // Swap '0' with the adjacent number
                    string newState = current;
                    int newIndex = newRow * 3 + newCol;
                    swap(newState[zeroIndex], newState[newIndex]);

                    // Add the new state if not visited
                    if (!visited.count(newState))
                    {
                        queue.push(newState);
                        visited.insert(newState);
                    }
                }
            }
        }
        steps++;
    }
    return -1; // Return -1 if the puzzle cannot be solved
}

int main()
{
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    cout << "Minimum steps to solve the puzzle: " << slidingPuzzle(board) << endl;
    return 0;
}
