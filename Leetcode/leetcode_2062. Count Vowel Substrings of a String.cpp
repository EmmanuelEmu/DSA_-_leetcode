#include <bits/stdc++.h>
using namespace std;

int countVowelSubstrings(string word)
{
    int n = word.size();
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        map<char, int> mp;
        for (int j = i; j < n; ++j)
        {
            char c = word[j];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                mp[c]++;
                if (mp.size() == 5)
                {
                    count++;
                }
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

int main()
{
    string word;
    cin >> word;
    cout << countVowelSubstrings(word) << endl;
    return 0;
}