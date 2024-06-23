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

map<char, pair<int, int>> direction_map;
bool validate_path(string path, int target_x, int target_y, string directions);

void solve(){
    // code here
    d_n(path_length);
    string path;
    cin >> path;

    int final_x = 0, final_y = 0;
    for (int i = 0; i < path_length; i++) 
    {
        pair<int, int> move = direction_map[path[i]];
        final_x += move.F;
        final_y += move.S;
    }
    
    if (final_x % 2 != 0 || final_y % 2 != 0) 
    {
        no;
        return;
    }
    
    final_x = final_x / 2;
    final_y = final_y / 2;
    
    string result_path = path;
    
    if (final_x == 0 && final_y == 0) 
    {
        int counts[2] = {0, 0};
        for (int i = 0; i < path_length; i++) 
        {
            if (path[i] == 'N') 
            {
                counts[0]++;
            }
            if (path[i] == 'S') 
            {
                counts[1]++;
            }
        }
        
        bool valid_flag = false;
        
        if (counts[0] != 0 && counts[1] != 0) 
        {
            for (int i = 0; i < path_length; i++) 
            {
                if (path[i] == 'N') 
                {
                    result_path[i] = 'R';
                    break;
                }
            }
            for (int i = 0; i < path_length; i++) 
            {
                if (path[i] == 'S') 
                {
                    result_path[i] = 'R';
                    break;
                }
            }
            for (int i = 0; i < path_length; i++) 
            {
                if (result_path[i] != 'R') 
                {
                    result_path[i] = 'H';
                }
            }
            if (validate_path(result_path, final_x, final_y, path)) 
            {
                valid_flag = true;
                cout << result_path << endl;
            }
        }
        
        if (!valid_flag) 
        {
            result_path = path;
            counts[0] = 0;
            counts[1] = 0;
            
            for (int i = 0; i < path_length; i++) 
            {
                if (path[i] == 'E') 
                {
                    counts[0]++;
                }
                if (path[i] == 'W') 
                {
                    counts[1]++;
                }
            }
            
            if (counts[0] != 0 && counts[1] != 0) 
            {
                for (int i = 0; i < path_length; i++) 
                {
                    if (path[i] == 'E') 
                    {
                        result_path[i] = 'R';
                        break;
                    }
                }
                for (int i = 0; i < path_length; i++) 
                {
                    if (path[i] == 'W') 
                    {
                        result_path[i] = 'R';
                        break;
                    }
                }
                for (int i = 0; i < path_length; i++) 
                {
                    if (result_path[i] != 'R') 
                    {
                        result_path[i] = 'H';
                    }
                }
                if (validate_path(result_path, final_x, final_y, path))
                {
                    valid_flag = true;
                    cout << result_path << en;
                } 
                else 
                {
                    no;
                }
            } 
            else 
            {
                no;
            }
        }
    } 
    else if (final_x >= 0 && final_y >= 0) 
    {
        int temp_x = 0, temp_y = 0;
        for (int i = 0; i < path_length; i++) 
        {
            if (path[i] == 'E' && temp_x != final_x) 
            {
                temp_x++;
                result_path[i] = 'R';
            } 
            else if (path[i] == 'N' && temp_y != final_y) 
            {
                temp_y++;
                result_path[i] = 'R';
            }
        }
        for (int i = 0; i < path_length; i++) 
        {
            if (result_path[i] != 'R') 
            {
                result_path[i] = 'H';
            }
        }
        if (validate_path(result_path, final_x, final_y, path)) 
        {
            cout << result_path << en;
        } 
        else 
        {
            no;
        }
    } 
    else if (final_x <= 0 && final_y >= 0) 
    {
        int temp_x = 0, temp_y = 0;
        for (int i = 0; i < path_length; i++) 
        {
            if (path[i] == 'W' && temp_x != final_x) 
            {
                temp_x--;
                result_path[i] = 'R';
            } 
            else if (path[i] == 'N' && temp_y != final_y) 
            {
                temp_y++;
                result_path[i] = 'R';
            }
        }
        for (int i = 0; i < path_length; i++) 
        {
            if (result_path[i] != 'R') 
            {
                result_path[i] = 'H';
            }
        }
        if (validate_path(result_path, final_x, final_y, path)) 
        {
            cout << result_path << en;
        } 
        else 
        {
            no;
        }
    } 
    else if (final_x <= 0 && final_y <= 0) 
    {
        int temp_x = 0, temp_y = 0;
        for (int i = 0; i < path_length; i++) 
        {
            if (path[i] == 'W' && temp_x != final_x) 
            {
                temp_x--;
                result_path[i] = 'R';
            } 
            else if (path[i] == 'S' && temp_y != final_y) 
            {
                temp_y--;
                result_path[i] = 'R';
            }
        }
        for (int i = 0; i < path_length; i++) 
        {
            if (result_path[i] != 'R') 
            {
                result_path[i] = 'H';
            }
        }
        if (validate_path(result_path, final_x, final_y, path)) 
        {
            cout << result_path << en;
        } 
        else 
        {
            no;
        }
    } 
    else 
    {
        int temp_x = 0, temp_y = 0;
        for (int i = 0; i < path_length; i++) 
        {
            if (path[i] == 'E' && temp_x != final_x) 
            {
                temp_x++;
                result_path[i] = 'R';
            } 
            else if (path[i] == 'S' && temp_y != final_y) 
            {
                temp_y--;
                result_path[i] = 'R';
            }
        }
        for (int i = 0; i < path_length; i++) 
        {
            if (result_path[i] != 'R') 
            {
                result_path[i] = 'H';
            }
        }
        if (validate_path(result_path, final_x, final_y, path)) 
        {
            cout << result_path << en;
        } 
        else 
        {
            no;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    direction_map['N'] = {0, 1};
    direction_map['S'] = {0, -1};
    direction_map['E'] = {1, 0};
    direction_map['W'] = {-1, 0};
    while (t--){
        solve();
    }
    return 0;
}

bool validate_path(string path, int target_x, int target_y, string directions) 
{
    int current_x = 0;
    int current_y = 0;
    int horizontal_count = 0;
    int vertical_count = 0;
    
    for(int i = 0; i < path.size(); i++) 
    {
        if(path[i] == 'H') 
        {
            horizontal_count++;
        } 
        else 
        {
            vertical_count++;
        }
    }
    
    if(horizontal_count == 0 || vertical_count == 0) 
    {
        return false;
    }
    
    for (int i = 0; i < path.size(); i++) 
    {
        if (path[i] == 'H') 
        {
            pair<int, int> move = direction_map[directions[i]];
            current_x += move.F;
            current_y += move.S;
        }
    }
    
    if (current_x != target_x || current_y != target_y) 
    {
        return false;
    }
    
    return true;
}

