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
#define finl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define en "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve(){
    // code here
    int n;
    cin >> n;
    vi a(n, 0), temp(n+1, 0);
    fl(i, n){
        cin >> a[i];
        temp[a[i]]++;
    }
    ll mex1 = 0;
    fl(i, n+1){
        if (temp[i] == 0){
            mex1 = i;
            break;
        }
    }
    bool flag = true;
    ll mex2 = n;
    fl(i, n+1){
        if (flag and temp[i] == 1){
            flag = false;
        }
        else if (!flag and temp[i] == 1){
            mex2 = i;
            break;
        }
    }
    cout << min(mex1, mex2) << en;
    
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