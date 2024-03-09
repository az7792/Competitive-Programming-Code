#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e2 + 10;
const ll MOD = 1000000007;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int f(int n)
{
    if (n == 1)
        return 1;
    int N = n;
    set<int> S;
    for (int i = 2; i <= n / i; ++i)
    {
        while (n % i == 0)
        {
            S.insert(i);
            n /= i;
        }
    }
    if (n > 1)
        S.insert(n);
    int ans = N;
    int mu = 1;
    int z = 1;
    for (auto v : S)
    {
        z *= v - 1;
        mu *= v;
    }
    return N * z / mu;
}
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
    // ll k, sum = 0;
    // cin >> k;
    // for (int n = 1; n <= k; ++n)
    // {
    //     for (int i = 1; i <= n; ++i)
    //     {
    //         ll t = n / i;
    //         sum += f(i) * t;
    //     }
    // }
    // cout << sum << endl;
    ll k;
    cin >> k;
    k %= MOD;
    // cout << (k * k * k + 3 * (k * k) + 2 * k) / 6 << endl;
    ll tmp = (POW(k, 3) + (3 * POW(k, 2)) % MOD + (2 * k) % MOD) % MOD;
    cout << (tmp * POW(6, MOD - 2)) % MOD << endl;
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