#include <bits/stdc++.h>
using namespace std;

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) return;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}
    

int main()
{

    int n;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int k;
    cin >> k;
    rotate(nums, k);
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}