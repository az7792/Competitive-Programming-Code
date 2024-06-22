#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;

inline ll FUN(ll v, ll N, ll nd, ll nv) { return v >= nd ? (N / v - 1) : (nv - v); }

ll PrimeSum(ll N)
{
    ll *S, *V, r = (ll)sqrt(N);
    ll nd = N / r;
    ll nv = r + nd - 1;
    V = new ll[nv], S = new ll[nv];
    for (ll i = 0; i < r; i++)
        V[i] = N / (i + 1);
    for (ll i = r; i < nv; i++)
        V[i] = V[i - 1] - 1;
    for (ll i = 0; i < nv; i++)
        S[i] = V[i] * (V[i] + 1) / 2 - 1;
    for (ll p = 2; p <= r; p++)
    {
        if (S[nv - p] > S[nv - p + 1])
        {
            ll sp = S[nv - p + 1];
            ll p2 = p * p;
            for (ll i = 0; i < nv; i++)
            {
                if (V[i] >= p2)
                    S[i] -= p * (S[FUN(V[i] / p, N, nd, nv)] - sp);
                else
                    break;
            }
        }
    }
    return S[0];
}

ll Pow(ll a, ll b, ll MOD)
{
    ll ans = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    if (n == 1)
        cout << 0 << endl;
    else
    {
        ll sum = PrimeSum(n + 1);
        ll SUM = (((2 + n + 1) % k) * (n % k)) % k;
        SUM = (SUM * Pow(2, k - 2, k)) % k;
        cout << (sum % k + SUM - 4) % k << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
