#include <bits/stdc++.h>
using namespace std;

bool isUgly(int n)
{
    n = abs(n);
    if (n == 0)
    {
        return false;
    }
    if (n == 1)
    {
        return true;
    }
    vector<int> res;
    for (auto i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
        }
        while (n % i == 0)
        {
            n /= i;
        }
    }
    if (n != 1)
    {
        res.push_back(n);
    }

    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    for(auto it : res){
        if(it!=2 && it!=3 && it!=5){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << isUgly(n) << endl;
    return 0;
}