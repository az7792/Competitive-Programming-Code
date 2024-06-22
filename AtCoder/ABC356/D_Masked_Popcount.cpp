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
int get(int n)
{
    bitset<60> a(n);
    return a.count();
}
ll n, m;
vector<ll> dp(60, 0);
vector<ll> DP(60, 0);
vector<ll> sum(60, 0);
bitset<60> a, b;
ll dfs(int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
    {
        ll tmp = get(0 & m) + get(1 & m);
        return tmp;
    }
    ll res = dp[p - 1];
    ll P = -1;
    for (int i = p - 1; i >= 0; --i)
    {
        if (b[i] == 1)
        {
            P = i;
            break;
        }
    }
    res += dfs(P) + (a[p] == b[p] && a[p] == 1) * (sum[p - 1]+1);
    res %= MOD;
    return res;
}
void solve()
{
    cin >> n >> m;
    a = bitset<60>(m);
    b = bitset<60>(n);
    sum[0] = b[0];
    for (int i = 1; i < 60; ++i)
    {
        sum[i] = sum[i - 1] + b[i] * (1ll << i);
        sum[i] %=MOD;
    }
    // ll ans1 = 0;
    // for (int i = 0; i <= n; ++i)
    // {
    //     ans1 += get((i & m));
    // }
    // cout << ans1 << endl;
    if (n == 0)
    {
        cout << 0;
        return;
    }
    dp[0] = a[0];
    for (int i = 1; i < 60; ++i)
    {
        dp[i] = (2 * dp[i - 1]) % MOD + (a[i] == 1 ? (1ll << i) % MOD : 0ll);
        dp[i] %= MOD;
    }
    ll ans = 0, p;
    for (int i = 59; i >= 0; --i)
    {
        if (b[i] == 1)
        {
            p = i;
            break;
        }
    }

    cout << dfs(p);
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
