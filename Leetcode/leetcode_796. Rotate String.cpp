#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal)
{
    int n = s.size();
    if (n != goal.size())
    {
        return false;
    }
    for (auto i = 0; i < n; i++)
    {
        auto it = distance(goal.begin(), find(goal.begin(), goal.end(), s[i]));
        if (s[i + 1] == goal[it + 1] || i == n - 1)
        {
            // cout << s[i + 1] << " " << goal[it + 1] << endl;
            goal.erase(remove(goal.begin(), goal.end(), s[i]), goal.end());
            goal.erase(remove(goal.begin(), goal.end(), s[i + 1]), goal.end());
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s, goal;
    cin >> s >> goal;
    cout << rotateString(s, goal) << endl;
    return 0;
}