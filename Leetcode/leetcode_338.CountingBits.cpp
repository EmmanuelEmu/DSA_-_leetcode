#include <bits/stdc++.h>
using namespace std;

int decToBin(int n){
    
    int sum = 0;
    while (n>0)
    {   
        sum+=(n%2);
        n = n/2;
    }
    return sum;
}

vector<int> countBits(int n)
{
    vector<int> result;
    for (auto i = 0; i < n+1; i++)
    {
        result.push_back(decToBin(i));
    }
    return result;
}

int main()
{

    int n;
    cin >> n;
    vector<int> res = countBits(n);
    for (auto it : res)
    {
        cout << it << " "; 
    }
    cout << endl;
    return 0;
}