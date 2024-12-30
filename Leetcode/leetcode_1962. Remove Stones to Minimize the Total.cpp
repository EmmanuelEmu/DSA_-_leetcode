#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    int n = piles.size();
    priority_queue<int> pq(piles.begin(), piles.end());
    long long sum = 0;
    for (auto it : piles)
    {
        sum += it;
    }
    while (k--)
    {
        int top = pq.top();
        pq.pop();
        int newTop = top - (top / 2);
        sum -= (top / 2);
        pq.push(newTop);
    }
    return sum;

}

int main()
{

    return 0;
}