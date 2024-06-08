class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        double answer = 0;
        num1.push_back(INT_MAX);
        num2.push_back(INT_MAX);
        vector<int> ans;
        int k = 0, j = 0;
        while (!(num1[k] == INT_MAX and num2[j] == INT_MAX)) {
            if (num1[k] <= num2[j]) {
                ans.push_back(num1[k]);
                k++;
            }
            else if (num2[j] < num1[k]) {
                ans.push_back(num2[j]);
                j++;
            }
        }
        // for (auto sf: ans) {
        //     cout << sf << " ";
        // }
        // cout << endl;
        if (ans.size()&1) {
            answer = ans[ans.size()/2];
        }
        else {
            long t1 = ans[ans.size()/2];
            long t2 = ans[(ans.size()/2)-1];
            answer = (t1+t2)/2.0;
        }
        return answer;
    }
};
