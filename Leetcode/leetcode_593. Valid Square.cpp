#include <bits/stdc++.h>
using namespace std;

int distance(vector<int> &point1, vector<int> &point2)
{
    int dx = point1[0] - point2[0];
    int dy = point1[1] - point2[1];
    return dx * dx + dy * dy;
}
bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
{
    vector<vector<int>> points = {p1, p2, p3, p4};
    vector<int> distances;
    for (auto i = 0; i < points.size(); i++)
    {
        for (auto j = i + 1; j < points.size(); j++)
        {
            distances.push_back(distance(points[i], points[j]));
        }
    }

    sort(distances.begin(), distances.end());

    for (auto it : distances)
    {
        cout << it << " ";
    }
    cout << endl;

    return distances[0] > 0 && // Ensure no zero distance (no overlapping points)
           distances[0] == distances[1] &&
           distances[1] == distances[2] &&
           distances[2] == distances[3] && // 4 equal sides
           distances[4] == distances[5] && // 2 equal diagonals
           distances[4] > distances[0];
}
int main()
{       
    vector<int> p1 = {1, 0};
    vector<int> p2 = {-1, 0};
    vector<int> p3 = {0, 1};
    vector<int> p4 = {0, -1};
    bool result = validSquare(p1, p2, p3, p4);
    cout << result << endl;
    return 0;
}