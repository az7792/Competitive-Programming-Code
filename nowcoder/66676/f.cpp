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
map<pll, ll> mp;
ll dfs(ll x, ll n)
{
    x %= MOD;
    if (mp.find({x, n}) != mp.end())
        return mp[{x, n}];
    if (n == 0)
    {
        mp[{x, n}] = x;
        return x;
    }
    if (n == 1)
    {
        mp[{x, n}] = (x * x) % MOD;
        return (x * x) % MOD;
    }
    ll a = n / 2;
    ll t = dfs(x, a);
    ll tt = dfs(t, n - a);
    mp[{x, n}] = tt;
    return tt;
}
ll POW(ll a, ll b)
{
    a = a % MOD;
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
void solve()
{
    ll n, x;
    cin >> n >> x;
    x %= MOD;
    // ll sum = 0;
    // for (int i = 0; i <= (POW(2, n + 1)) - 1; ++i)
    //     sum = (sum + POW(x, i)) % MOD;
    // cout << "sum:" << sum;
    // cout << endl;
    if (x == 1)
    {
        cout << POW(2, n + 1);
    }
    else
    {
        // sum = (POW(x,2^(n+1))-1)/(x-1);
        cout << ((dfs(x, n + 1) - 1 + MOD) % MOD * POW(x - 1, MOD - 2)) % MOD;
    }
    // cerr << ct;
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