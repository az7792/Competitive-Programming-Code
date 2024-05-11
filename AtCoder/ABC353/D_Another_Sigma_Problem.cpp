#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
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
    int n;
    cin >> n;
    vector<ll> a(n + 2), sum(n + 2, 0), b(n + 2), ten(n + 2), sumten(n + 2, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = to_string(a[i]).size();
        ten[i] = POW(10ll, b[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        sum[i] = (sum[i + 1] + a[i]) % MOD;
        sumten[i] = (sumten[i + 1] + ten[i]) % MOD;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll t1 = sum[i + 1];
        ll t2 = sumten[i + 1];
        ans += (a[i] % MOD * t2) % MOD;
        ans += t1;
        ans %= MOD;
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
