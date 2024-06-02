class Solution {
    vector<int> index(vector<string> &af, string s) {
        vector<int> id;
        for (int i{0}; i<af.size(); i++) {
            if (af[i] == s) {
                id.push_back(i);
            }
        }
        return id;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> af = strs;
        set<string> st;
        for (int i{0}; i<af.size(); i++) {
            sort(af[i].begin(), af[i].end());
            st.insert(af[i]);
        }
        vector<vector<string>> ans;
        for (auto &k: st) {
            vector<int> ind;
            vector<string> temp;
            ind = index(af, k);
            for (auto l: ind) {
                temp.push_back(strs[l]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

