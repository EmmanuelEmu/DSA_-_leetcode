#include <bits/stdc++.h>
using namespace std;

int incremovableSubarrayCount(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = i; j < n; j++)
        {
            bool flag = true;
            for(auto k=j+1; k<n-1; k++){
                if(nums[k] >= nums[k+1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                count++;
            }
        }
    }
    return count;
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
    cout << incremovableSubarrayCount(nums) << endl;
  return 0;
}