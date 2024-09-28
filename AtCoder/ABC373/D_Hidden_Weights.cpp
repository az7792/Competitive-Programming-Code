#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n + 1), gF(n + 1);
    vector<ll> ans(n + 1, 0);
    vector<bool> vis(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        gF[v].emplace_back(u, w);
    }
    function<void(int)> dfs = [&](int p)
    {
        if (vis[p] == 1)
            return;
        for (auto [x, y] : g[p])
        {
            if (vis[x])
                continue;
            ans[x] = y + ans[p];
            vis[p] = 1;
            dfs(x);
        }
        for (auto [x, y] : gF[p])
        {
            if (vis[x])
                continue;
            ans[x] = ans[p] - y;
            vis[p] = 1;
            dfs(x);
        }
    };
    for (int i = 1; i <= n; ++i)
        dfs(i);
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
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
