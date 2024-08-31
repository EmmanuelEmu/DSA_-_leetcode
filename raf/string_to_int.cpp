#include <bits/stdc++.h>
#include <string> // For isalpha and tolower functions
using namespace std;

bool processString(const string &s)
{
    string result = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
        {
            result += tolower(s[i]);
        }
    }
    string temp = result;
    reverse(temp.begin(), temp.end());
    cout << result << " " << temp << endl;
    bool resBool = (result == temp);
    cout << resBool << endl;
    return resBool;
}

int main()
{
    string s = "0P";
    
    bool result = processString(s);
    cout << result << endl; // Expected output: "amanaplanacanalpanama"
    return 0;
}
