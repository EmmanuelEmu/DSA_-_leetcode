#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, int n, vector<int> &quantities)
{
    int noOfShopRequired = 0;
    for (auto it : quantities)
    {
        noOfShopRequired += it / mid;
        if (it % mid != 0)
        {
            noOfShopRequired++;
        }
    }
    return noOfShopRequired <= n;
}

int minimizedMaximum(int n, vector<int> &quantities)
{
    int low = 0;
    int high = *max_element(quantities.begin(), quantities.end());
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, n, quantities))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> quantities;
    while (m--)
    {
        int a;
        cin >> a;
        quantities.push_back(a);
    }
    cout << minimizedMaximum(n, quantities) << endl;    
    return 0;
}