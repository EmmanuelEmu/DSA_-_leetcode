#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if(numRows == 1){
        return s;
    }
    vector<vector<char>> res(numRows);
    bool downFlag = true;
    int row = 0;
    int charPtr = 0;
    int n = s.size();
    while(charPtr < n && row < numRows){
        if(downFlag){
            res[row].push_back(s[charPtr]);
            row++;
            if(row == numRows-1){
                downFlag = false;
            }
        }
        else{
            res[row].push_back(s[charPtr]);
            row--;
            if(row == 0){
                downFlag = true;
            }
        }
        charPtr++;
    }
    string zigzagString = "";
    for(auto row : res){
        for(auto ch : row){
            zigzagString += ch;
        }
    }
    return zigzagString;
}

int main()
{
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << convert(s, numRows) << endl;
    return 0;
}