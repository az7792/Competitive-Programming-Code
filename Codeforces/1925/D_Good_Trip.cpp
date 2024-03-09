#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
ll POW(ll a, ll b)
{
    a %= MOD;
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> dp(k + 1, 0);
    vector<ll> a(m + 1);
    ll sum = 0;
    for (int i = 0; i < m; ++i)
    {
        ll t1, t2;
        cin >> t1 >> t2 >> a[i + 1];
        sum += a[i + 1];
    }
    ll N = (n - 1) * n / 2;
    N = POW(N, MOD - 2);
    ll z = N - m;
    ll ans = 0;
    dp[1] = (sum % MOD * N) % MOD;
    for (int i = 2; i <= k; ++i)
    {
        sum = (sum + ((m * N) % MOD)) % MOD;
        // dp[i] = (sum + ((m * N) % MOD))%MOD;
        dp[i] = (sum * N) % MOD;
        // sum = ((((sum + 1) * N) % MOD) * m) % MOD;

        ans += dp[i];
        ans %= MOD;
    }
    ans += dp[1];
    ans %= MOD;
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
