#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct combN
{
    ll mod;
    vector<ll> jc;
    combN(ll n, ll MMmod) // C(n,x),模
    {
        mod = MMmod;
        jc.resize(n + 1);
        jc[0] = 1;
        for (ll i = 1; i <= n; ++i)
            jc[i] = (jc[i - 1] * i) % mod;
    }
    ll POW(ll a, ll b)
    {
        if (b == 0)
            return 1;
        if (b % 2 == 0)
            return POW((a * a) % mod, b / 2) % mod;
        else
            return (POW((a * a) % mod, b / 2) % mod * a) % mod;
    }

    ll C(ll a, ll b) // a中选b个
    {
        if (b == 0)
            return 1;
        return (jc[a] * POW((jc[b] * jc[a - b]) % mod, mod - 2)) % mod;
    }
};

struct combN2
{
    ll mod;
    vector<vector<ll>> C;

    combN2(int n, ll m) : mod(m)
    {
        C.assign(n + 1, vector<ll>(n + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            C[i][0] = C[i][i] = 1 % mod;
            for (int j = 1; j < i; j++)
            {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }
    }

    ll get(int n, int m)
    {
        if (m < 0 || m > n)
            return 0;
        return C[n][m];
    }
};

void solve()
{
    combN cc(100, 998244353);
    cout << cc.C(10, 3); // n个里选5个
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
