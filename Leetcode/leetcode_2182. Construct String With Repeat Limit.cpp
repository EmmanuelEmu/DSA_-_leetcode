#include <bits/stdc++.h>
using namespace std;

string repeatLimitedString(string s, int repeatLimit)
{
    map<char, int, greater<char>> mp;
    for (auto ch : s)
    {
        mp[ch]++;
    }

    string res = "";

    while (!mp.empty())
    {
        auto lexicograph = mp.begin();
        char lexicoChar = lexicograph->first;
        int freq = lexicograph->second;

        int needToAppend = min(repeatLimit, freq);
        res.append(needToAppend, lexicoChar);
        lexicograph->second -= needToAppend;

        if (lexicograph->second == 0)
        {
            mp.erase(lexicograph);
        }
        else
        {
            if (mp.size() > 1)
            {
                auto nextLexicoGraph = next(mp.begin());
                res += nextLexicoGraph->first;
                nextLexicoGraph->second--;

                if (nextLexicoGraph->second == 0)
                {
                    mp.erase(nextLexicoGraph);
                }
            }
            else
            {
                break;
            }
        }
    }

    return res;
}

int main()
{
    string s;
    int limit;
    cin >> s >> limit;
    cout << repeatLimitedString(s, limit) << endl;
    return 0;
}