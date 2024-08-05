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
#define finl(i, j, k) for(long long i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
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
    int n;
    cin >> n;
    long double te = n;
    string s;
    cin >> s;
    vl temp(n+1, 0);
    ll cnt = 0;
    for (int i{1}; i<n+1; i++){
        if(s[i-1] == '1'){
            temp[i] = temp[i-1]+1;
            cnt++;
        }
        else {
            temp[i] = temp[i-1];
        }
    }
    map<long double,ll> m;
    // if(temp[n] == 0){
    //     cout << 0 << en;
    //     return;
    // }
    if (n&1){
        if(temp[n/2] >= n/2+1){
            cout << 0 << en;
            return;
        }
    }
    if(!(n&1)){
        if(temp[n/2] >= n/2){
            cout << 0 << en;
            return;
        }
    }
    if(temp[n] >= te/2){
        m[te/2] = 0;
    }
    finl(i, 1, n+1){
        long double tei = i;
        long double ten = n-i;
        if(i-temp[i] >= tei/2 and cnt-temp[i] >= ten/2){
            long double sef = abs((te/2)-i);
            if(m.find(sef) == m.end()){
                m[sef] = i;
            }
        }
    }
    if(m.size() > 0){
        for (auto &it: m){
            cout << it.second << en;
            return;
        }
    }
    else {
        cout << 0 << en;
        return;
    }
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}