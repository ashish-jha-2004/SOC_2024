#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

/*
****************************************************************************************************************************************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
****************************************************************************************************************************************************************************************************************************************************************************
    मनोबुद्ध्यहङ्कारचित्तानि नाहं न च श्रोत्रजिह्वे न च घ्राणनेत्रे ।
    न च व्योम भूमिर्न तेजो न वायुश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥१॥
    
    न च प्राणसंज्ञो न वै पञ्चवायुर्न वा सप्तधातुर्न वा पञ्चकोशाः ।
    न वाक्पाणिपादं न चोपस्थपायुश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥२॥
    
    न मे द्वेषरागौ न मे लोभमोहौ मदो नैव मे नैव मात्सर्यभावः ।
    न धर्मो न चार्थो न कामो न मोक्षश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥३॥
    
    न पुण्यं न पापं न सौख्यं न दुःखं न मन्त्रो न तीर्थं न वेदा न यज्ञाः ।
    अहं भोजनं नैव भोज्यं न भोक्ता चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥४॥  
    
    न मृत्युर्न शङ्का न मे जातिभेदः पिता नैव मे नैव माता न जन्म ।
    न बन्धुर्न मित्रं गुरुर्नैव शिष्यश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥५॥
    
    अहं निर्विकल्पो निराकाररूपो विभुत्वाञ्च सर्वत्र सर्वेन्द्रियाणाम् ।
    न चासङ्गतं नैव मुक्तिर्न मेयश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥६॥
****************************************************************************************************************************************************************************************************************************************************************************
*/

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for(int i{0}; i<j; i++)
#define fb(i, j, k) for (int i{j}; i>=k; i--)
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define d_n(n) ll n; cin >> n
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i]
#define en "\n"
#define F first
#define S second
#define PB push_back
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

// Utility Function
template <class T> 
using ind_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename T>
void pt(T &&t)  { cout << t << "\n"; }
template<typename T>
ll sv(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// Number Theory
const ll MOD = 1e9+7, mod = MOD;
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll modpow(ll x, ll n, int m = MOD){if (x == 0 && n == 0) return 0; ll res = 1; while (n > 0){ if (n % 2) res = (res * x) % m; x = (x * x) % m; n /= 2; } return res; }
int modinv(int x, int m = MOD) { return modpow(x, m - 2, m);}
ll binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(ll a) { return bitset<64>(a).to_string(); }
ll factorial(ll n){if (n==0){ return 1;} ll ans=1;for (ll i=1;i<=n;i++) { ans=mod_mul(ans,i); } return ans; }
ll nCr(ll n, ll r) { if (n<r){ return 0;} ll ans=factorial(n); ans=mod_mul(ans,inv(factorial(r))); ans=mod_mul(ans,inv(factorial(n-r))); return ans; }

void solve(){
    // code here
    d_n(n);
    vl v(n);
    map<ll, ll> mp;
    ll total = 0;
    fl(i, n) {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto &k: mp) {
        ll x = k.S;
        if (x >= 2) {
            total += (x*(x-1))/2;
        }
    }
    // cerr << total;
    fl(i, n) {
        if (mp[v[i]] < 2) {
            cout << total << en;
        }
        else if (mp[v[i]] == 2) {
            cout << total - 1 << en;
        }
        else {
            ll x = mp[v[i]];
            ll ans = (x*(x - 1))/2;
            ll temp = total - ans;
            ans = ((x-1)*(x-2))/2;
            temp = temp + ans;
            cout << temp << en;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // d_n(t);
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}