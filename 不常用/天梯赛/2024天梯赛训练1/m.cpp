#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
struct node
{
    ll x, len;
    bool operator<(const node a) const
    {
        return len > a.len;
    }
};
void solve()
{
    int n, m, q, u, v;
    ll c, d;
    cin >> n >> m >> q;
    vector<ll> a(n + 1);
    vector<vector<pair<int, ll>>> G(n + 1);
    vector<vector<pair<int, ll>>> g(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> c >> d;
        G[u].push_back({v, c});
        g[v].push_back({u, d});
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    priority_queue<node> Q;
    vector<ll> disa(n + 1, 1e18);
    vector<ll> disb(n + 1, 1e18);
    disa[1] = disb[n] = 0;
    Q.push({1, 0});
    while (!Q.empty())
    {
        node t = Q.top();
        Q.pop();
        if (disa[t.x] < t.len)
            continue;
        for (auto [x, y] : G[t.x])
        {
            if (disa[x] > t.len + y)
            {
                disa[x] = t.len + y;
                Q.push({x, disa[x]});
            }
        }
    }
    Q.push({n, 0});
    while (!Q.empty())
    {
        node t = Q.top();
        Q.pop();
        if (disb[t.x] < t.len)
            continue;
        for (auto [x, y] : g[t.x])
        {
            if (disb[x] > t.len + y)
            {
                disb[x] = t.len + y;
                Q.push({x, disb[x]});
            }
        }
    }
    multiset<ll> s;
    for (int i = 1; i <= n; ++i)
    {
        ll tmpans;
        if (disa[i] != 1e18 && disb[i] != 1e18)
            tmpans = disa[i] + ((disb[i] + a[i] - 1) / a[i]);
        else
            tmpans = 1e18;
        s.insert(tmpans);
    }
    while (q--)
    {
        int x;
        ll ta;
        cin >> x >> ta;
        if (disa[x] != 1e18 && disb[x] != 1e18)
        {
            ll tmpans = disa[x] + ((disb[x] + a[x] - 1) / a[x]);
            s.erase(s.find(tmpans));
            a[x] = ta;
            tmpans = disa[x] + ((disb[x] + a[x] - 1) / a[x]);
            s.insert(tmpans);
        }
        cout << *s.begin() << endl;
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
