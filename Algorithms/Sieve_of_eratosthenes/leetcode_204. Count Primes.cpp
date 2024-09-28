#include <bits/stdc++.h>
using namespace std;


//Using the sieve of Eratosthenes
int countPrimes(int n)
{
    vector<int> prime(n + 1, 1);
    for(int i = 2; i<=sqrt(n); i++){
        if(i==0 || i==1) prime[i] = 0;
        if(prime[i]){
            for(int j = i*i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        if(prime[i]){
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countPrimes(n) << endl;
    return 0;
}