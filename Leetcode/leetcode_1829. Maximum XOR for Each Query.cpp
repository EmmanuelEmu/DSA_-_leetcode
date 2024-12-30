#include <bits/stdc++.h>
using namespace std;


int findXor(const vector<int>& arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num;
    }
    return result;
}


int findComplementForMaxBits(int xorValue, int maximumBit) {
    int allBitsSet = (1 << maximumBit) - 1;
    return xorValue ^ allBitsSet; 
}

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    int xorValue = findXor(nums);
    vector<int> res;

    for (int i = n - 1; i >= 0; i--) {
        int k = findComplementForMaxBits(xorValue, maximumBit);
        res.push_back(k);
        xorValue ^= nums[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    while (n--) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int maximumBit;
    cin >> maximumBit;
    vector<int> result = getMaximumXor(nums, maximumBit);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
