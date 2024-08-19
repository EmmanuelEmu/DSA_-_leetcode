#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    // Extract the hour, minute, second, and the period (AM/PM)
    stringstream ss(s);
    string token;
    vector<string> vs;

    while (getline(ss, token, ':'))
    {
        vs.push_back(token);
    }
    string otistic = vs[2];
    string numericPart = otistic.substr(0, otistic.size() - 2); // Extract "SS" from "SSAM" or "SSPM"
    string unit = otistic.substr(otistic.size() - 2);            // Extract "AM" or "PM"
    vs.pop_back(); // Remove the original seconds part
    vs.push_back(numericPart); // Add the cleaned seconds part

    if (unit == "AM")
    {
        if (vs[0] == "12")
        {
            vs[0] = "00"; // Convert 12 AM to 00
        }
    }
    else if (unit == "PM")
    {
        if (vs[0] != "12")
        {
            int militaryTime = stoi(vs[0]) + 12;
            vs[0] = to_string(militaryTime); // Convert PM hour to 24-hour format
        }
    }

    // Reconstruct the time in 24-hour format
    string result = vs[0] + ":" + vs[1] + ":" + vs[2];
    return result;
}

int main()
{
    string s;
    getline(cin, s);

    string result = timeConversion(s);
    cout << result << endl;

    return 0;
}
