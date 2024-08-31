#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> minVec = nums1.size() > nums2.size() ? nums2 : nums1;
    vector<int> maxVec = nums1.size() > nums2.size() ? nums1 : nums2;

    vector<int> result;

    // std::sort(minVec.begin(), minVec.end());
    // // Step 2: Use std::unique to remove duplicates
    // auto it = std::unique(minVec.begin(), minVec.end());
    // // Step 3: Erase the "removed" elements
    // minVec.erase(it, minVec.end());

    for (auto num : minVec)
    {
        auto it = std::find(maxVec.begin(), maxVec.end(), num);
        // auto it1 = std::find(minVec.begin(), minVec.end(), num);
        if (it!=maxVec.end())
        {
            result.push_back(num);
            maxVec.erase(it);
        }
        
    }
    return result;   
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1, nums2;
    while (n--)
    {
        int a;
        cin >> a;
        nums1.push_back(a);
    }
    while (m--)
    {
        int b;
        cin >> b;
        nums2.push_back(b);
    }

    vector<int> res = intersection(nums1, nums2);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}