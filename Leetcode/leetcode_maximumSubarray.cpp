#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxSum = nums[0];
    for(auto item: nums){
        sum += item;
        maxSum = max(maxSum, sum);
        if (sum <0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{

    int n;
    vector<int> arr;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int maximumSum = maxSubArray(arr);
    cout << maximumSum << endl;
    return 0;
}