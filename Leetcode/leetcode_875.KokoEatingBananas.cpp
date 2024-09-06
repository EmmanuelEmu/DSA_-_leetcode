#include <bits/stdc++.h>
using namespace std;

int totalHours(vector<int> &piles, int hr) {
    long long totalHrs = 0;
    for (int pile : piles) {
        totalHrs += (pile + hr - 1) / hr; 
    }
    return totalHrs;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int lb = 1;
    auto maxElement = max_element(piles.begin(), piles.end());
    int ub = *maxElement;
    int ans;
    while (lb<=ub)
    {
        int mid = lb+(ub-lb)/2; 
        int hourReq = totalHours(piles, mid);
        // cout << hourReq << " " << mid << endl;
        if (hourReq <= h)
        {
            ans = mid;
            ub = mid-1;
        } else
        {
            lb = mid+1;
        }
    }

    return ans;
    
}

int main()
{

    int n;
    vector<int> v;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int h;
    cin >> h;
    int res = minEatingSpeed(v, h);
    cout << res << endl;
    return 0;
}