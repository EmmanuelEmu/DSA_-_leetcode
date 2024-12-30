#include <bits/stdc++.h>
using namespace std;

long long maxKelements(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int> pq(nums.begin(), nums.end());
    long long sum = 0;
    while (k--)
    {
        int top = pq.top();
        // cout << top << " " << ceil((top / 3.0)) << endl;
        pq.pop();
        sum += top;
        int newTop = ceil(top / 3.0);
        pq.push(newTop);
    }
    cout << endl;
    return sum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << maxKelements(nums, k) << endl;
    return 0;
}