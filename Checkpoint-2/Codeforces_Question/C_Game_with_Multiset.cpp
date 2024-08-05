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
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i];
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

ll v[30];

void solve(){
    // code here
    d_n(n);
    d_n(k);
    if (n == 1) v[k]++;
    else {
        int temp1 = k, temp2 = k;
        // iterating in the forward direction
        fl(i, 30){
            ll p = pow(2, i);
            if (temp1 - p*v[i] == 0){
                yes
                return;
            }
            else if (temp1 - p*v[i] > 0){
                temp1 -= p*v[i];
            }
            else {
                if (temp1%p == 0){
                    yes
                    return;
                }
                else {
                    temp1 -= (temp1/p)*p;
                }
            }
        }
        // Iterating in the backward direction
        for (int i{29}; i>=0; i--){
            ll p = pow(2, i);
            if (temp2 - p*v[i] == 0){
                yes
                return;
            }
            else if (temp2 - p*v[i] > 0){
                temp2 -= p*v[i];
            }
            else {
                if (temp2%p == 0){
                    yes
                    return;
                }
                else {
                    temp2 -= (temp2/p)*p;
                }
            }
        }
        no
        return;
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