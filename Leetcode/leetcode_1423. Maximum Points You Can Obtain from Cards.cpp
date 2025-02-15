#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += cardPoints[i];
    }

    int lsum = sum, rsum = 0;
    int maxSum = sum;

    for (int i = 0; i < k; i++)
    {
        lsum -= cardPoints[k - 1 - i];
        rsum += cardPoints[n - 1 - i];
        maxSum = max(maxSum, lsum + rsum);
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> cardPoints;
    while (n--)
    {
        int a;
        cin >> a;
        cardPoints.push_back(a);
    }
    int k;
    cin >> k;
    cout << maxScore(cardPoints, k) << endl;

    return 0;
}