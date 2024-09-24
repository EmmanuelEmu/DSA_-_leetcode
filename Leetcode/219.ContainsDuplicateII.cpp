#include <bits/stdc++.h>
using namespace std;

// bool containsNearbyDuplicate(vector<int> &nums, int k)
// {
//     for (auto i = 0; i < nums.size(); i++)
//     {
//         int target = nums[i];
//         auto nextTar = find(nums.begin()+(i+1), nums.end(), target);
//         if (nextTar != nums.end()){
//             int idx = std::distance(nums.begin(), nextTar);
//             if (abs(idx - i) <= k)
//             {
//                 // cout << i << " " << idx << endl;
//                 return true;
//             }
//         }
//     }

//     return false;
// }

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (auto i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) != mp.end())
        {
            if (abs(mp[nums[i]] - i) <= k)
            {
                return true;
            }
        }
        mp[nums[i]] = i;
    }
    return false;
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
    cout << containsNearbyDuplicate(nums, k) << endl;
    return 0;
}