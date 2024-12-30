#include <bits/stdc++.h>
using namespace std;

string compressedString(string word)
{
    sort(word.begin(), word.end());
    string ans = "";
    int count = 1;
    
    for (int i = 0; i < word.size(); i++)
    {
        if (i < word.size() - 1 && word[i] == word[i + 1])
        {
            count++;
            if (count == 9)
            {
                ans += to_string(count);
                ans += word[i];
                count = 1; // Reset to 1 instead of 0
                i++;
            }
        }
        else
        {
            ans += to_string(count);
            ans += word[i];
            count = 1;
        }
    }
    
    return ans;
}


int main()
{
    string word;
    cin >> word;
    cout << compressedString(word) << endl;
    return 0;
}