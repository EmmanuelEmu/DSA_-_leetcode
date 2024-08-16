#include <bits/stdc++.h>
using namespace std;

int countTriples(int n)
{
    vector<vector<int>> triplets;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double result = sqrt(pow(i, 2) + pow(j, 2));
            int target = static_cast<int>(result);

            // Ensure the target is an integer and lies within the bounds
            if (target <= n && result == target && target != i && target != j)
            {
                vector<int> temp = {i, j, target};
                triplets.push_back(temp);
            }
        }
    }

    // Print the triplets
    // for (const auto &triplet : triplets)
    // {
    //     for (int num : triplet)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    return triplets.size()*2;
}

int main()
{

    int n;
    cin >> n;
    int result = countTriples(n);
    cout << result << endl;
    return 0;
}