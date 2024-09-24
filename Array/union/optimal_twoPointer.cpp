#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    vector<int> res;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (res.empty() || res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (res.empty() || res.back() != arr2[j])
            {
                res.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (res.empty() || res.back() != arr1[i])
        {
            res.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (res.empty() || res.back() != arr2[j])
        {
            res.push_back(arr2[j]);
        }
        j++;
    }

    return res;
}

int main()
{

    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (auto i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (auto i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> uni = findUnion(arr1, arr2, n, m);
    for (auto it : uni)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}