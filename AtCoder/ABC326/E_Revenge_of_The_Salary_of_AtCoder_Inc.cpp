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
ll POW(ll a, ll b)
{
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
    vector<ll> y(n + 1);
    vector<ll> dp(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> y[i];
    dp[n] = y[n];
    ll N = POW(n, MOD - 2);
    ll sum = (dp[n] * N) % MOD;
    for (int i = n - 1; i >= 1; --i)
    {
        dp[i] = (y[i] + sum) % MOD;
        sum = (sum + (dp[i] * N) % MOD);
        sum %= MOD;
    }
    cout << sum;
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