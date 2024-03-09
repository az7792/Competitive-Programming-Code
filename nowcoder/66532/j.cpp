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
vector<vector<int>> G;
vector<bool> vis;
vector<ll> val;
ll ans;
ll dfs(int p)
{
    ll res = val[p];
    for (auto v : G[p])
    {
        if (!vis[v])
        {
            vis[v] = true;
            res += dfs(v);
        }
    }
    ans += res;
    return res;
}
void solve()
{
    G.clear();
    vis.clear();
    val.clear();
    int n;
    cin >> n;
    G.resize(n + 1);
    val.resize(n + 1, 0);
    vis.resize(n + 1, false);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<ll> tmp(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp[i];
    }
    sort(all(tmp), [](ll a, ll b)
         { return a > b; });
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        val[node] = tmp.back();
        tmp.pop_back();
        for (auto v : G[node])
        {
            if (!vis[v])
            {
                vis[v] = true;
                Q.push(v);
            }
        }
    }
    for (int i = 0; i <= n; ++i)
        vis[i] = false;
    vis[1] = true;
    ans = 0;
    dfs(1);
    cout << ans << endl;
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