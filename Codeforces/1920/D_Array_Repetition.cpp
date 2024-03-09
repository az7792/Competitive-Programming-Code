#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<ll> g;
vector<pair<ll, ll>> tmp;
int End;
ll query(ll x)
{
    int p = upper_bound(g.begin() + 1, g.begin() + End + 1, x) - g.begin();
    if (tmp[p - 1].first == 1)
    {
        if (g[p - 1] == x)
            return tmp[p - 1].second;
        else
        {
            return query((x % g[p - 1] == 0 ? g[p - 1] : x % g[p - 1]));
        }
    }
    if (tmp[p - 1].first == 2)
    {
        if (g[p - 1] == x)
            return query(x - tmp[p - 1].second * g[p - 2]);
        else
        {
            return query((x % g[p - 1] == 0 ? g[p - 1] : x % g[p - 1]));
        }
    }
    return 0;
}
void solve()
{
    g.clear();
    tmp.clear();
    int n, q;
    cin >> n >> q;
    End = n;
    g.resize(n + 1, 0);
    tmp.resize(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i)
        cin >> tmp[i].first >> tmp[i].second;
    for (int i = 1; i <= n; ++i)
    {
        if (tmp[i].first == 1)
        {
            g[i] = g[i - 1] + 1;
        }
        else
        {
            ll tt = 1e18 / g[i - 1];
            if (tmp[i].second + 1 > tt)
            {
                g[i] = (ll)1e18 + 1ll;
                End = i;
                break;
            }
            else
                g[i] = g[i - 1] * (tmp[i].second + 1);
        }
    }
    ll p;
    for (int i = 1; i <= q; ++i)
    {
        cin >> p;
        cout << query(p) << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
