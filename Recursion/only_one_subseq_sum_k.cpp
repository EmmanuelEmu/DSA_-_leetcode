#include <bits/stdc++.h>
using namespace std;

bool subSeq(int ind, vector<int> &res, int arr[], int s, int sum, int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : res)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    res.push_back(arr[ind]);

    s += arr[ind];
    if (subSeq(ind + 1, res, arr, s, sum, n) == true)
    {
        return true;
    }

    s -= arr[ind];
    res.pop_back();

    if (subSeq(ind + 1, res, arr, s, sum, n) == true)
    {
        return true;
    }

    return false;
}

int main()
{

    int arr[] = {1, 2, 1};
    int sum = 2;
    vector<int> vec;
    subSeq(0, vec, arr, 0, sum, 3);
    return 0;
}