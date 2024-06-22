#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll POW(ll a, ll b)
{
    ll result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % MOD; // 在这里取余
        }
        a = (a * a) % MOD; // 在这里取余
        b /= 2;
    }
    return result;
}
void solve()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll N = n + 1;
    ll M = m + 1;
    ll ans = (((n * m) % MOD) * ((N * M) % MOD)) % MOD;
    ans = (ans * POW(4, MOD - 2)) % MOD;
    ll tmp = (((x * y) % MOD) * (((N - x) * (M - y)) % MOD)) % MOD;
    cout << (ans - tmp + MOD) % MOD << endl;
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