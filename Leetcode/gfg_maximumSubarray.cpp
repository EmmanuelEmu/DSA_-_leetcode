#include <bits/stdc++.h>
using namespace std;

// long long pairWithMaxSum(long long arr[], long long N)
// {
//     long long maxSum = LLONG_MIN;

//     for (long long i = 0; i < N - 1; i++)
//     {
//         long long min1 = LLONG_MAX;
//         long long min2 = LLONG_MAX;
        
//         if (min1 > min2) {
//             swap(min1, min2);
//         }

//         for (long long j = i; j < N; j++)
//         {
//             if (arr[j] < min1)
//             {
//                 min2 = min1;
//                 min1 = arr[j];
//             }
//             else if (arr[j] < min2)
//             {
//                 min2 = arr[j];
//             }

//             long long sum = min1 + min2;
//             if (sum > maxSum)
//             {
//                 maxSum = sum;
//                 // Optional: Uncomment the next line if you want to print the pairs
//                 // cout << min1 << " " << min2 << endl;
//             }
//         }
//     }
//     return maxSum;
// }

long long pairWithMaxSum(long long arr[], long long N){
    long long maxSum = arr[0] + arr[1];
    for (auto i = 1; i <=N ; i++)
    {
        maxSum = max((arr[i]+arr[i-1]), maxSum);
    }
    return maxSum;
}

int main()
{
    int n;
    long long arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long result = pairWithMaxSum(arr, n);
    cout << result << endl;
    return 0;
}
