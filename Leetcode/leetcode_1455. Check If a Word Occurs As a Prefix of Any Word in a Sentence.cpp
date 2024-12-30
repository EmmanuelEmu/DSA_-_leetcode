#include <bits/stdc++.h>
using namespace std;

int isPrefixOfWord(string sentence, string searchWord)
{
    vector<string> v;
    stringstream ss(sentence);
    string temp;
    while (ss >> temp)
    {
        v.push_back(temp);
    }
    for (auto i = 0; i < v.size(); i++)
    {
        if (v[i].find(searchWord) == 0)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    string sentence, searchWord;
    getline(cin, sentence);
    getline(cin, searchWord);
    cout << isPrefixOfWord(sentence, searchWord) << endl;
    return 0;
}