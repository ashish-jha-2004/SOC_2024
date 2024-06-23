class Solution {
    int mul(vector<int> &nums) {
        int ans = 1;
        for (int i{0}; i<nums.size(); ++i) {
            ans *= nums[i];
        }
        return ans;
    }
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int sd = mul(nums);
        for (int i{0}; i<nums.size(); ++i) {
            if (nums[i] != 0)
                ans.push_back(sd/nums[i]);
            else {
                int m = 1;
                for (int j{0}; j<nums.size(); ++j) {
                    if (i == j) continue;
                    m *= nums[j];
                }
                ans.push_back(m);
            }
        }
        return ans;
    }
};
