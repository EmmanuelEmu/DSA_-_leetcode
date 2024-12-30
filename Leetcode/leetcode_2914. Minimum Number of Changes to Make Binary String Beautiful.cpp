#include <bits/stdc++.h>
using namespace std;

int minChanges(string s)
{
    int n = s.size();
    int count = 0;
    int sub = 1;
    for (auto i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            if (sub % 2 != 0)
            {
                count++;
                s[i - 1] = s[i];
                sub++;
            }
            else
            {
                sub = 1;
            }
        }
        else
        {
            sub++;
        }
    }
    return count;
}

int main()
{
    string s;
    cin >> s;
    cout << minChanges(s) << endl;
    return 0;
}