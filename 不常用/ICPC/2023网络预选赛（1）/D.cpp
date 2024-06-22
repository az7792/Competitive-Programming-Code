#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const ll MAX = 1e2 + 10;
const ll MOD = 998244353;
ll fa[MAX];
ll sum[MAX];
ll find(ll p)
{
    if (fa[p] != p)
    {
        fa[p] = find(fa[p]);
    }
    return fa[p];
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        ll fu = find(u);
        ll fv = find(v);
        if(fv!=fu)
        {
            sum[fv] += sum[fu] + 1;
            fa[fu] = fv;
        }
        else
        {
            sum[fu]++;
        }
    }
    for (int i = 1; i <= n; ++i)
        find(i);
    vector<pll> Node;
    map<ll, ll> mp;
    for (int i = 1; i <= n; ++i)
    {
        mp[fa[i]]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i] == i)
        {
            Node.push_back({mp[i], sum[i]});
        }
    }
    bool f = false;
    ll ans = 0;
    for (auto v : Node)
    {
        ll N = v.first;
        ll M = v.second;
        if (N * (N - 1) / 2 != M)
        {
            f = true;
            ans += N * (N - 1) / 2 - M;
        }
    }
    if (f)
        cout << ans;
    else
    {
        vector<ll> ttt;
        for (auto v : Node)
        {
            ttt.push_back(v.first);
        }
        sort(all(ttt));
        cout << ttt[0] * ttt[1];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}