#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    int max_val = 0;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        max_val = max(max_val, nums[i]);
    }

    vector<int> freq(max_val + 1, 0);

    for (int num : nums) {
        freq[num]++;
    }

    for (int i = max_val; i >= 1; --i) {
        int count = 0;
        for (int j = i; j <= max_val; j += i) {
            count += freq[j];
        }
        if (count >= 2) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
