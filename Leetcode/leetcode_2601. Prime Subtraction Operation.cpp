#include<bits/stdc++.h>

using namespace std;

vector<int> sieveEratosthenes(int n)
{
    vector<int> prime(n + 1, 1);
    vector<int> res;
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            res.push_back(i);
        }
    }

    return res;
}

bool primeSubOperation(vector<int> &nums)
{
    constexpr int kMax = 1000;
    const vector<int> primes = sieveEratosthenes(kMax);

    int prevNum = 0;
    for (int &num : nums)
    {
       
        const auto it = lower_bound(primes.begin(), primes.end(), num - prevNum);
        if (it != primes.begin())
        {
            num -= *(prev(it));
        }
        
        if (num <= prevNum)
            return false;
        
        prevNum = num;
    }

    return true;
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    bool result = primeSubOperation(nums);
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Is non-decreasing: " << (result ? "Yes" : "No") << endl;
    return 0;
}
