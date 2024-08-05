#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calculate_mad_sum(vector<ll>& a, int n) {
    ll total_sum = 0;
    while (true) {
        total_sum += accumulate(a.begin(), a.end(), 0LL);
        vector<ll> b(n);
        unordered_map<ll, ll> freq;
        ll current_mad = 0;
        bool all_zeros = true;

        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
            if (freq[a[i]] >= 2) {
                current_mad = max(current_mad, a[i]);
            }
            b[i] = current_mad;
            if (current_mad != 0) {
                all_zeros = false;
            }
        }
        
        a = move(b);
        if (all_zeros) break;
    }
    return total_sum;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << calculate_mad_sum(a, n) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
