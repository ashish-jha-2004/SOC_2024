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
#define sortall(v) sort(v.begin(), v.end())
#define d_n(n) ll n; cin >> n
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i];
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

void print(ll &n){
    fl(i, n){
        cout << i+1 << " ";
    }
    cout << en;
}

void solve(){
    // code here
    ll n;
    cin >> n;
    ll sum = 0;
    ll a = 1, b = 1;
    for (int i{0}; i<n; i++){
        sum += a*b;
        a++;
        b+=2;
    }
    ll m = n*2;
    cout << sum << " " << m << en;
    bool flag = false;
    for (int i{n}; i>=1; i--){
        cout << 1 << " " << i << " ";
        print(n);
        cout << 2 << " " << i << " ";
        print(n);
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