#include <bits/stdc++.h>
using namespace std;

int countPrefixes(vector<string> &words, string s)
{
    int count = 0;
    for(auto string : words){
        if(s.find(string) == 0){
            count++;
        }
    }
    return count;
}

int main()
{

    return 0;
}