#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (auto i = 0; i < nums.size(); i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (auto j = i + 1; j < nums.size(); j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int k = j + 1;
            int l = nums.size() - 1;
            while (k < l)
            {
                int sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    result.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                    while (k < l && nums[l] == nums[l + 1])
                    {
                        l--;
                    }
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    k++;
                }
            }
        }
    }

    // for (auto i = 0; i < result.size(); i++)
    // {
    //     for (auto j = 0; j < result[i].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}

int main()
{

    int n;
    cin >> n;
    vector<int> numbers;
    while (n--)
    {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    int target;
    cin >> target;
    vector<vector<int>> quards;
    quards = fourSum(numbers, target);
    return 0;
}