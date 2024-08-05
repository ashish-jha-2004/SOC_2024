#include<bits/stdc++.h>
using namespace std;
/*
************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
************************************************************************************************************************************************
    ॐ त्र्यम्बकं यजामहे
    सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान्
    मृत्योर्मुक्षीय मामृतात् ॥
************************************************************************************************************************************************
*/

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for(int i{0}; i<j; i++)
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define sort(v) sort(v.begin(), v.end())
#define d_n(n) ll n; cin >> n
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i]
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

void solve(){
    // code here
    d_n(n);
    d_n(k);
    d_v(v, n);
    vl ps(n, 0), ss(n, 0);
    ps[0] = v[0];
    ss[n-1] = v[n-1];
    ll sum = v[0];
    fn(i, 1, n){
        ps[i] = ps[i-1] + v[i];
        sum += v[i];
    }
    for (int i{n-2}; i>=0; i--){
        ss[i] = ss[i+1] + v[i];
    }
    reverse(ss.B, ss.E);
    int l1 = lower_bound(ps.B, ps.E, (k+1)/2) - ps.B;
    int l2 = lower_bound(ss.B, ss.E, (k/2)) - ss.B;
    reverse(ss.B, ss.E);
    l2 = n-l2-1;
    if (l1 > l2){
        cout << n << en;
    }
    else if (l1 < l2){
        ll ans = 0;
        if (ps[l1] > (k+1)/2){
            ans += l1;
        } 
        else {
            ans += l1+1;
        }
        if (ss[l2] > k/2){
            ans += n-l2-1;
        }
        else {
            ans += n-l2;
        }
        cout << ans << en;
    }
    else {
        if (sum > k){
            cout << n-1 << en;
        }
        else {
            cout << n << en;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    while (t--){
        solve();
    }
    return 0;
}