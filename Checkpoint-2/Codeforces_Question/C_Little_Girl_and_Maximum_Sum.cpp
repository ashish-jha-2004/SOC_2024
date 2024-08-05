#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> freq(n + 1, 0);
    
    // Read the queries and update the frequency array using the difference array approach
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        freq[l - 1]++;
        if (r < n) {
            freq[r]--;
        }
    }
    
    // Compute the prefix sums to get the actual frequency counts
    for (int i = 1; i < n; ++i) {
        freq[i] += freq[i - 1];
    }
    
    // Remove the extra element used for the difference array
    freq.pop_back();
    
    // Sort both the array and the frequency array
    sort(a.begin(), a.end());
    sort(freq.begin(), freq.end());
    
    // Calculate the maximum sum of query replies
    long long max_sum = 0;
    for (int i = 0; i < n; ++i) {
        max_sum += static_cast<long long>(a[i]) * freq[i];
    }
    
    cout << max_sum << endl;
    
    return 0;
}
