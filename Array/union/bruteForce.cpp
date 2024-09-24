#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    set<int> uniqueEl;
    for (auto i = 0; i < n; i++)
    {
        uniqueEl.insert(arr1[i]);
    }

    for (auto i = 0; i < m; i++)
    {
        uniqueEl.insert(arr2[i]);
    }

    vector<int> uni(uniqueEl.size());
    int ind = 0;
    for (auto it : uniqueEl)
    {
        uni[ind++] = it;
    }

    return uni;
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