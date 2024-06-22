#include <bits/stdc++.h>//ji
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll POW(ll a, ll b)
{
    a %= MOD;
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW(a * a, b / 2) % MOD;
    return (POW(a * a, b / 2) % MOD * a) % MOD;
}
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll L = i + 1, R = n - i + 1;
        if (L == R)
            ans = (ans + POW(2, MOD - 2)) % MOD;
        else if (L < R)
        {
            R = i + L - 1;
            ll len = (R + n) / 2;
            len = len - (n) / 2 + 1;
            ans = ans + ((POW(2, len) - 1 + MOD) % MOD) * (POW(POW(2, len + 1), MOD - 2));
            ans %= MOD;
        }
        else
        {
            L = i - R + 1;
            ll len = (L + 1) / 2;
            len = (n + 1) / 2 - len + 1;
            ans = ans + ((POW(2, len) - 1 + MOD) % MOD) * (POW(POW(2, len + 1), MOD - 2));
            ans %= MOD;
        }
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