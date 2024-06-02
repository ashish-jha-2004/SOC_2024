class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i{0}; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vp;
        for (auto &l: mp) {
            vp.push_back({l.second, l.first});
        }
        sort(vp.rbegin(), vp.rend());
        vector<int> ans;
        for (int i{0}; i<k; i++) {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};

