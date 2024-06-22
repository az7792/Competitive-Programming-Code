#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 1e6 + 10;
ll MOD = 998244353;
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
void solve()
{
    ll n, ct, num, ans = 1;
    cin >> n;
    while (n != 0)
    {
        ct = n / MOD, num = n % MOD;
        ans = ((ans * POW(jc[MOD - 1], ct)) % MOD * jc[num]) % MOD;
        n = ct;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t >> MOD;
    init();
    while (t--)
    {
        solve();
    }
    return 0;
}
