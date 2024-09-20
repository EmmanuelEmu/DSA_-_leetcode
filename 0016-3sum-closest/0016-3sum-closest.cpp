class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int diff = INT_MAX;
    int ans = 0;
    for (auto i = 0; i < n; i++)
    {
        if (i>0 && nums[i]==nums[i-1])
        {
            continue;
        }
        int lb = i+1;
        int ub = n-1;
        while (lb<ub)
        {
            int sum = nums[i]+nums[lb]+nums[ub];
            if (abs(target-sum)<diff)
            {
                diff = abs(target-sum);
                ans = sum;
            }
            if (sum>target)
            {
                ub--;
            }
            else
            {
                lb++;
            }
        }
    }
    return ans;        
}
};