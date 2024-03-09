#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
ll Mymemcpy(ll a, int p)
{
    return a & ((1ll << p) - 1ll);
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll k;
    vector<bool> vis(n + 1, 0);
    while (q--)
    {
        ll ans = 0;
        cin >> k;
        for (int i = 1; i <= n; ++i)
            vis[i] = 0;
        vector<int> tmpvis;
        for (int i = 60; i >= 0; --i)
        {
            ll tk = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (vis[j] == 1)
                {
                    tk += (1ll << i);
                }
                else
                {
                    int now = (a[j] >> i) & 1;
                    if (now == 0)
                    {
                        tk += (1ll << i) - Mymemcpy(a[j], i);
                        tmpvis.push_back(j);
                    }
                    if (tk > k)
                        break;
                }
            }
            if (tk <= k)
            {
                k -= tk;
                ans += (1ll << i);
                for (auto v : tmpvis)
                    vis[v] = 1;
            }
            tmpvis.clear();
        }
        cout << ans << endl;
    }
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
