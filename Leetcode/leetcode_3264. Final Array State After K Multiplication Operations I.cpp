#include <bits/stdc++.h>
using namespace std;

vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    for(auto i=1; i<=k; i++){
        int minIndex = min_element(nums.begin(), nums.end())- nums.begin();
        nums[minIndex] = nums[minIndex]*multiplier;
    }
    return nums;
}

int main()
{
    
    return 0;
}