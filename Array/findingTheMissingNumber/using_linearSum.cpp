#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int summmation = (n*(n+1))/2;

    int sum = 0;
    for (auto i = 0; i < n; i++)
    {
        sum+=nums[i];
    }
    
    return summmation - sum;
}


int main(){

    int n;
    cin >> n;
    vector<int> v;
    for (auto i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << missingNumber(v) << endl;
    
    return 0;
}