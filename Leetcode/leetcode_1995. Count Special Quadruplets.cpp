#include <bits/stdc++.h>
using namespace std;

int countQuadruplets(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
    for (auto i = 0; i < n; i++)
    {
        for (auto j = i + 1; j < n; j++)
        {
            for (auto k = j + 1; k < n; k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(find(nums.begin(), nums.end(), sum) != nums.end()){
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}