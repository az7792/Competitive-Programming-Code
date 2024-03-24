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
struct Math
{
    ll mod;
    vector<bool> nisp; // false 是质数
    vector<int> isp;

    Math(ll MMod)
    {
        mod = MMod;
    }

    ll gcd(ll a, ll b)
    {
        while (b != 0)
        {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ll exgcd(ll a, ll b, ll &x, ll &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }
        ll res = exgcd(b, a % b, x, y);
        ll t = x;
        x = y;
        y = t - (a / b) * y;
        return res;
    }

    ll lcm(ll a, ll b)
    {
        return (a * b) / gcd(a, b);
    }

    ll POW(ll a, ll b)
    {
        a %= mod;
        if (b == 0)
            return 1;
        if (b % 2 == 0)
            return POW((a * a) % mod, b / 2) % mod;
        else
            return (POW((a * a) % mod, b / 2) % mod * a) % mod;
    }

    void initOula(int n) // 1-n的素数
    {
        nisp.resize(n + 1, 0);
        nisp[0] = nisp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (!nisp[i])
                isp.push_back(i);
            for (int j = 0; j < isp.size() && isp[j] * i <= n; ++j)
            {
                nisp[isp[j] * i] = true;
                if (i % isp[j] == 0)
                    break;
            }
        }
    }

    bool isPrime(int x)
    {
        if (x <= 1)
            return 0;
        for (int i = 2; i <= x / i; ++i)
            if (x % i == 0)
                return 0;
        return 1;
    }
};
void solve()
{
    ll a, b;
    cin >> a >> b;
    vector<ll> s;
    for (ll i = 2; i <= a / i; ++i)
    {
        while (a % i == 0)
        {
            s.push_back(i);
            a /= i;
        }
    }
    if (a > 1)
        s.push_back(a);
    map<ll, ll> mp;
    for (auto v : s)
        mp[v]++;

    bool ok = false;
    if (b % 2 == 0)
        ok = true;
    for (auto v : mp)
        if ((b * v.second + 1) % 2 == 0)
        {
            ok = true;
            break;
        }

    b %= MOD;
    ll ans = b;
    for (auto v : mp)
    {
        (ans *= (b * v.second + 1) % MOD) %= MOD;
    }
    Math math(MOD);
    if (ok)
        cout << (ans * math.POW(2, MOD - 2)) % MOD;
    else
        cout << ((ans - 1 + MOD) % MOD * math.POW(2, MOD - 2)) % MOD;
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
