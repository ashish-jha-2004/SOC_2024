class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i{0}; i<nums.size(); i++){
            if (lower_bound(nums.begin()+i+1, nums.end(), nums[i]) != nums.end() and *lower_bound(nums.begin()+i+1, nums.end(), nums[i]) == nums[i]) {
                return true;
            }
        }
        return false;
    }
};
