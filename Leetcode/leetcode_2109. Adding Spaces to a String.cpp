#include <bits/stdc++.h>
using namespace std;

string addSpaces(string s, vector<int> &spaces)
{
    string res;
    int spaceIndex = 0;
    int n = spaces.size();

    for (int i = 0; i < s.size(); ++i)
    {
        // If current index matches a space position, add a space
        if (spaceIndex < n && i == spaces[spaceIndex])
        {
            res += ' ';
            spaceIndex++;
        }
        // Add the current character
        res += s[i];
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> spaces;
    while (n--)
    {
        int a;
        cin >> a;
        spaces.push_back(a);
    }
    cout << addSpaces(s, spaces) << endl;
    return 0;
}