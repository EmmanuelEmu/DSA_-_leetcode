#include <bits/stdc++.h>
using namespace std;

// Trim leading spaces
string ltrim(const string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    return (start == string::npos) ? "" : s.substr(start);
}

// Trim trailing spaces
string rtrim(const string &s)
{
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

int lengthOfLastWord(string s)
{
    // cout << s << endl;
    s = rtrim(s);
    if (s.size() == 1)
    {
        return 1;
    }
    
    // cout << s << endl;)
    int end = s.size() - 1;
    int count = 0;
    while (s[end] != ' ')
    {
        if (end == 0)
        {
            return count+1;
        }
        
        // cout << s[end];
        count++;
        end--;
    }
    // cout << endl;
    return count;
}

int main()
{

    string s;
    getline(cin, s);
    int result = lengthOfLastWord(s);
    cout << result << endl;
    return 0;
}