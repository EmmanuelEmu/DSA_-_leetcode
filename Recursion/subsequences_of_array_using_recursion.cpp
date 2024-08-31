// #include<bits/stdc++.h>
// using namespace std;

// void printVec(vector<int> arr){
//     for (auto num: arr)
//     {
//         cout << num << " ";
//     }
//     cout << endl;
// }

// void subS(int ind, vector<int>&result, int arr[], int n){
//     if (ind==n)
//     {
//         printVec(result);
//         return;
//     }
//     result.push_back(arr[ind]);
//     subS(ind+1, result, arr, n);
//     result.pop_back();
//     subS(ind+1, result, arr, n);
// }

// int main(){

//     int arr [] = {2, 4, 5};
//     int n=3;
//     vector<int>ds;
//     subS(0, ds, arr, n);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int subs(int ind, vector<int> &result, vector<int> &nums, int cnt, int n, int target)
{
    if (ind == n)
    {
        if (!result.empty()) // Ensure it's a non-empty subsequence
        {
            int min_value = *std::min_element(result.begin(), result.end());
            int max_value = *std::max_element(result.begin(), result.end());
            if (min_value + max_value <= target)
            {
                cnt++;
            }
        }
        return cnt;
    }

    // Include the current element
    result.push_back(nums[ind]);
    cnt = subs(ind + 1, result, nums, cnt, n, target);

    // Exclude the current element
    result.pop_back();
    cnt = subs(ind + 1, result, nums, cnt, n, target);

    return cnt;
}

int numSubseq(vector<int> &nums, int target)
{
    vector<int> res;
    return subs(0, res, nums, 0, nums.size(), target);
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int target;
    cin >> target;
    int result = numSubseq(arr, target);
    cout << "Total number of valid subsequences: " << result << endl;
    return 0;
}
