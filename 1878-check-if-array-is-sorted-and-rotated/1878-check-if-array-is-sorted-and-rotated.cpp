class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(auto i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                ind = i;
            }
        }
        if(ind == -1){
            return true;
        }
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        int rotate = n-ind;
        for(auto i=0; i<n; i++){
            if(nums[i]!= sortedNums[(i+rotate)%n]){
                return false;
            }
        }
        return true;
    }
};