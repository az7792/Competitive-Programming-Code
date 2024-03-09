#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll jc[MAX];
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
    jc[0] = 1;
    for (ll i = 1; i < MAX; ++i)
        jc[i] = (jc[i - 1] * i) % MOD;
}
ll C(ll a, ll b) // a中选b个
{
    if (b == 0)
        return 1;
    return (jc[a] * POW((jc[b] * jc[a - b]) % MOD, MOD - 2)) % MOD;
}
void solve()
{
    ll n = 100;
    cout << C(n, 5); // n个里选5个
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
