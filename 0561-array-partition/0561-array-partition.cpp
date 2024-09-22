class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int minSum = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto i=0; i<n; i=i+2){
            minSum+=min(nums[i], nums[i+1]);
        }

        return minSum;
    }
};