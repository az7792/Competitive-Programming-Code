#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void COUT(vector<ll> &a, vector<ll> &b)
{
    cout << a.size() << ' ';
    for (auto v : a)
        cout << v << " ";
    cout << endl;
    cout << b.size() << ' ';
    for (auto v : b)
        cout << v << " ";
    cout << endl;
}
void solve()
{
    ll n, s1, s2;
    cin >> n >> s1 >> s2;
    bool f = 1;
    if (s1 > s2)
        swap(s1, s2), f = 0;
    vector<pll> r(n);
    for (int i = 0; i < n; ++i)
        cin >> r[i].first, r[i].second = i + 1;
    sort(all(r), [&](pll a, pll b)
         { return a.first > b.first; });
    vector<ll> a, b;
    for (int i = 0; i < n; ++i)
    {
        if (r[i].first * (a.size() * s1 + s1) >= r[i].first * (b.size() * s2 + s2))
            b.eb(r[i].second);
        else
            a.eb(r[i].second);
    }
    if (f)
        COUT(a, b);
    else
        COUT(b, a);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}