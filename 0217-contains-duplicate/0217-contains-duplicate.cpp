class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0;

        for(auto ind = low+1; ind<nums.size(); ind++){
            if(nums[low] == nums[ind]){
                return true;
            }
            low++;
        }

        return false;
    }
};