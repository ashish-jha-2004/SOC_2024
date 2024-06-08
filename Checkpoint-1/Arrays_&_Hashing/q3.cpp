#include<set>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        multiset<long> s;
        for (int i{0} ; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        for (int i{0}; i<nums.size(); i++) {
            long temp = nums[i];
            s.erase(s.find(nums[i]));
            if (!s.empty() and s.find(target - nums[i]) != s.end()) {
                ans.push_back(i);
                int l = nums.size()-1;
                for (; l>=0; l--){
                    if (nums[l] == target - nums[i]) {
                        break;
                    }
                }
                ans.push_back(l);
                break;
            }
            s.insert(temp);
        }return ans;

    }
};
