#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> palindromePairs(vector<string> &words)
{
    vector<vector<int>> res;

    for (auto i = 0; i < words.size(); i++)
    {
        for (auto j = i + 1; j < words.size(); j++)
        {
            string merged = words[i] + words[j];
            string revMerged = words[j] + words[i];
            if (merged == string(merged.rbegin(), merged.rend()))
            {
                res.push_back({i, j});
            }
            if (revMerged == string(revMerged.rbegin(), revMerged.rend()))
            {
                res.push_back({j, i});
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words;
    while (n--)
    {
        string a;
        cin >> a;
        words.push_back(a);
    }
    vector<vector<int>> res = palindromePairs(words);
    for (auto v : res)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}