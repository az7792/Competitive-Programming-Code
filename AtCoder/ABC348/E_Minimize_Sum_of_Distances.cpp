#include <bits/stdc++.h> //ji
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
vector<vector<int>> g;
vector<ll> sum, dp, a;
void dfs(int p, int fa, int sp)
{
    dp[1] += sp * a[p];
    sum[p] += a[p];
    for (auto &v : g[p])
        if (v != fa)
        {
            dfs(v, p, sp + 1);
            sum[p] += sum[v];
        }
}
void DFS(int p, int fa)
{
    for (auto &v : g[p])
    {
        if (fa != v)
        {
            dp[v] = dp[p] + sum[1] - 2 * sum[v];
            DFS(v, p);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    g.clear(), dp.clear(), sum.clear(), a.clear();
    g.resize(n + 1), dp.resize(n + 1, 0), sum.resize(n + 1, 0), a.resize(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dfs(1, 0, 0);
    DFS(1, 0);
    cout << *min_element(dp.begin() + 1, dp.end());
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
