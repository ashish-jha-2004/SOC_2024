#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll calc_subseg(ll i, ll n, ll maxS, ll preS[], ll dp[]) {
    if (i < 0) return 0;

    ll target = preS[i] + maxS;
    auto lbIdx = lower_bound(preS, preS + n + 1, target) - preS;

    if (lbIdx == n + 1)
        dp[i] += (n - i);
    else if (target == preS[lbIdx])
        dp[i] += (lbIdx - i) + dp[lbIdx + 1];
    else
        dp[i] += (lbIdx - i - 1) + dp[lbIdx];

    return dp[i] + calc_subseg(i - 1, n, maxS, preS, dp);
}

void proc_seg() {
    ll n, maxS;
    cin >> n >> maxS;
    ll arr[n], preS[n + 1] = {0}, dp[n + 3] = {0};
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
        preS[i + 1] = preS[i] + arr[i];
    }
    
    ll totalValid = calc_subseg(n - 1, n, maxS, preS, dp);

    cout << totalValid << endl;
}

int main() {
    ll t = 1;
    cin >> t;
    
    while (t--) {
        proc_seg();
    }
    
    return 0;
}
