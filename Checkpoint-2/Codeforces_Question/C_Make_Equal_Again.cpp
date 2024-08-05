#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)


void solution(ll n){
    vector<ll> v(n);
    unordered_map<ll, ll> mp;
    fl(i, n){
        cin >> v[i];
        mp[v[i]]++;
    }
    ll p = 1, s{1};
    for (int i{1}; i<n; i++){
        if (v[i-1] == v[i]){
            p++;
        }
        else {
            break;
        }
    }
    for (int i{n-2}; i>=0; i--){
        if (v[i] == v[i+1]){
            s++;
        }
        else {
            break;
        }
    }
    //cout << p << " " << s << endl;
    if (p == n){
        cout << 0 << endl;
        return;
    }
    if (v[0] == v[n-1]){
        cout << n-(p+s) << endl;
        return;
    }
    cout << n-max(p, s) << "\n";
}

int main(){
    int t;
    cin >> t;
    ll n;
    while (cin >> n){
        solution(n);
    }
    return 0;
}