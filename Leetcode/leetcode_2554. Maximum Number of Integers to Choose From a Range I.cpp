#include <bits/stdc++.h>
using namespace std;

int maxCount(vector<int> &banned, int n, int maxSum)
{
    int maxEl = *max_element(banned.begin(), banned.end());
    int count = 0;
    vector<int> hash(maxEl + 1, 0);
    for (auto num : banned)
    {
        hash[num]++;
    }
    int sum = 0;
    for (auto i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            sum += i;
            if(sum <= maxSum){
                count++;
            } else{
                break;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> banned;
    int maxSum;
    while (n--)
    {
        int a;
        cin >> a;
        banned.push_back(a);
    }
    int num;
    cin >> num;
    cin >> maxSum;
    cout << maxCount(banned, num, maxSum) << endl;
    return 0;
}