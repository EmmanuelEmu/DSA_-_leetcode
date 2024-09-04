#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &nums, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if ((mid == 0 || nums[mid] != nums[mid - 1]) && 
        (mid == nums.size() - 1 || nums[mid] != nums[mid + 1])) {
        return nums[mid];
    }

    int part1 = singleElement(nums, low, mid - 1);
    int part2 = singleElement(nums, mid + 1, high);

    return part1 == -1 ? part2 : part1;
}

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0;
    int high = nums.size();
    int res = singleElement(nums, low, high);
    return res;
}

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int res = singleNonDuplicate(v);
    cout << res << endl;
    return 0;
}