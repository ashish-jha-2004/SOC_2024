#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;

void solve() {
    ll n, x;
    cin >> n >> x;
    vl coin(n);
    for (ll i = 0; i < n; i++) {
        cin >> coin[i];
    }

    vector<ll> dp(x + 1, 0);
    dp[0] = 1; // There's one way to make 0 amount (use no coins)

    for (ll i = 0; i < n; i++) {
        for (ll j = coin[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coin[i]]) % MOD;
        }
    }

    cout << dp[x] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
