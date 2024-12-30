#include <bits/stdc++.h>
using namespace std;

int maximumLength(string s)
{
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string subString = "";
        for (int j = i; j < n; j++)
        {
            if ((j > 0 && s[j] == s[j - 1]) || j == 0)
            {
                subString += s[j];
            }
            else
            {
                continue;
            }
            int cnt = 0;
            for (int k = 0; k <= n - subString.size(); k++)
            {
                string str = "";
                for (int l = k; l < k + subString.size(); l++)
                {
                    str += s[l];
                }
                if (str == subString)
                {
                    cnt++;
                }
            }
            if (cnt >= 3 && count < subString.size())
            {
                count = subString.size();
            }
        }
    }

    return count == 0 ? -1 : count;
}

int main()
{
    string s;
    cin >> s;
    cout << maximumLength(s) << endl;
    return 0;
}