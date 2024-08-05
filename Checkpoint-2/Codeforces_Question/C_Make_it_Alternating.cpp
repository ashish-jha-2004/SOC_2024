#include<bits/stdc++.h>
using namespace std;

/*
************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
************************************************************************************************************************************************
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
************************************************************************************************************************************************
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
template <typename T>
void print(T &&t)  { cerr << t << "\n"; }
void printarr(ll arr[], ll n){fl(i,n) cerr << arr[i] << " ";cerr << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();fl(i,n)cerr<<v[i]<<" ";cerr<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}

// Mathematical Function
ll gcd(ll a, ll b){
    if (b == 0)return a;
    return gcd(b, a % b);
} 
ll lcm(ll a, ll b){
    return (a/gcd(a,b)*b);
}
string decToBinary(int n){
    string s="";
    int i = 0;
    while (n > 0) {
        s =to_string(n % 2)+s;
        n = n / 2;
        i++;
    }return s;
}
ll binaryToDecimal(string n){
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for(int i = len - 1; i >= 0; i--){
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(ll n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i=5; i*i<=n; i+=6)
        if(n%i == 0 || n%(i + 2) == 0) return false;
    return true;
}
bool isPowerOfTwo(ll n){
    if(n == 0)return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x){
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
const ll MOD = 998244353;

ll fact(ll n){
    if (n == 1) return 1;
    if (n == 0) return 1;
    return (n*fact(n-1))%MOD;
}

void solve(){
    // code here
    string s;
    cin >> s;
    vector<string> v;
    ll cnt1 = 0;
    fn(i, 1, s.size()){
        if (s[i] == s[i-1]){
            cnt1++;
        }
    }
    for (int i{0}; i<s.size();){
        string k;
        int j{i};
        for (; j<s.size(); j++){
            if (s[j] == s[i]){
                k.PB(s[j]);
            }
            else break;
        }
        v.PB(k);
        i = j;
    }
    // printvec(v);
    // cout << fact(100000) << en;
    ll ans = 1, cnt2 = 0;
    for (auto &k: v){
        
        if (k.size() > 1) ans = ((ans%MOD) * (k.size()%MOD))%MOD;
    }
    cout << cnt1 << " " << ((ans%MOD) * (fact(cnt1)%MOD))%MOD<< en;
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