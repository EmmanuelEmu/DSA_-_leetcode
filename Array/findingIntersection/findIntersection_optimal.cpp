#include <bits/stdc++.h>
using namespace std;

// this is the optimal solution to finding the intersection of two sorted arrays using two pointer method

vector<int> findIntersection(int arr1[], int arr2[], int n, int m)
{
    vector<int> res;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
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

    vector<int> res = findIntersection(arr1, arr2, n, m);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}