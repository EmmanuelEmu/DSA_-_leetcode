#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int largest = a[0];
        int secondLargest = -1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > largest)
            {
                secondLargest = largest;
                largest = a[i];
            }
            else if (a[i] > secondLargest && a[i] != largest)
            {
                secondLargest = a[i];
            }
        }
        cout << secondLargest+largest << endl;
    }
    // your code goes here

    return 0;
}