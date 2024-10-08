#include <bits/stdc++.h>
using namespace std;



string getPermutation(int n, int k)
{
    vector<int> nums;
    int fact = 1;
    for (auto i = 1; i < n; i++)
    {
        fact *= i;
        nums.push_back(i);
    }

    string res = "";
    nums.push_back(n);
    k--;
    while (true)
    {
        res += to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if (nums.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact /= nums.size();
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string res = getPermutation(n, k);
    cout << res << endl;
    
    return 0;
}