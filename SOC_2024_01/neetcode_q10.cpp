class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (*lower_bound(nums.begin(), nums.end(), target) != target) return -1;
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

