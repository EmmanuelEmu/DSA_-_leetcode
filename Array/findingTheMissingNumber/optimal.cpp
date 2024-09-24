#include<bits/stdc++.h>
using namespace std;


int missingNumber(vector<int>& nums) {

    int xor1, xor2;
    xor1 = xor2 = 0;
    for (auto i = 0; i < nums.size(); i++)
    {
        xor1 = xor1 ^ nums[i];
        xor2 = xor2 ^ (i+1);
    }

    xor2 = xor2 ^ (nums.size()+1);
    return xor1 ^ xor2;
}

int main(){

    vector<int> v;
    int n;
    cin >> n;
    for (auto i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    cout << missingNumber(v) << endl;   
    return 0;
}