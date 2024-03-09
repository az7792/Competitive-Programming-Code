#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll sum[100010];
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
void init()
{
    sum[0] = 1;
    for (ll i = 1; i < 100010; ++i)
        sum[i] = (sum[i - 1] * i) % MOD;
}
ll C(ll a, ll b) // a中选b个
{
    if (b == 0)
        return 1;
    return (sum[a] * POW((sum[b] * sum[a - b]) % MOD, MOD - 2)) % MOD;
}
void solve()
{
    ll n, a;
    cin >> n;
    vector<ll> tmp;
    ll ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        tmp.push_back(a);
        if (i % 3 == 0)
        {
            sort(all(tmp));
            if (tmp[0] == tmp[1] && tmp[1] == tmp[2])
                ans = (ans * 3) % MOD;
            else if (tmp[0] == tmp[1])
                ans = (ans * 2) % MOD;
            tmp.clear();
        }
    }
    n /= 6;
    // Cn0^2 + Cn1^2 + ... + Cnn^2
    ll Tmp = 0;
    for (int i = 0; i <= n; ++i)
    {
        ll ttt = C(n, i);
        ttt = (ttt * ttt) % MOD;
        Tmp = (Tmp + ttt) % MOD;
    }
    cout << (ans * Tmp) % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    init();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
