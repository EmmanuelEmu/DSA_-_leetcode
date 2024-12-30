#include <bits/stdc++.h>
using namespace std;

vector<string> possibleChanges(vector<string> usernames)
{
    vector<string> res;

    for (const auto &user : usernames)
    {
        bool flag = false;
        char suffixMin = 'z' + 1;

        for (int i = user.size() - 1; i >= 0; --i)
        {
            if (user[i] > suffixMin)
            {
                flag = true;
                break;
            }
            suffixMin = min(suffixMin, user[i]);
        }

        res.push_back(flag ? "YES" : "NO");
    }

    return res;
}

int main()
{
    vector<string> usernames;
    int n;
    cin >> n;
    while (n--)
    {
        string user;
        cin >> user;
        usernames.push_back(user);
    }
    vector<string> res = possibleChanges(usernames);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}