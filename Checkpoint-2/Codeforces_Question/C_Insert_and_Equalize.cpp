#include <bits/stdc++.h>
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for (int i{0}; i < j; i++)
#define fn(i, j, k) for (int i{j}; i < k; i++)
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define all(v) v.begin(), v.end()
#define d_n(n) \
    ll n;      \
    cin >> n
#define d_v(v, n) \
    vl v(n);      \
    fl(i, n) cin >> v[i]
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(vl &arr, int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

void solve()
{
    // code here
    d_n(n);
    d_v(v, n);
    if (n == 1)
    {
        cout << 1 << en;
        return;
    }
    sort(all(v));
    vl v1;
    fn(i, 0, n - 1)
    {
        v1.PB(v[n - 1] - v[i]);
    }
    ll mini = *min_element(all(v1));
    ll aj = findGCD(v1, v1.size());
    ll ax = v[n - 1] + aj;
    set<ll> s;
    for (auto &a : v)
    {
        s.insert(a);
    }
    fl(i, n)
    {
        if (s.find(v[n - 1] - (i + 1) * aj) == s.end())
        {
            ax = v[n - 1] - (i + 1) * aj;
            break;
        }
    }
    v.PB(ax);
    sort(all(v));
    ll ans = 0;
    for (auto &a : v)
    {
        ans += (v.back() - a) / aj;
    }
    cout << ans << en;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    while (t--)
    {
        solve();
    }
    return 0;
}