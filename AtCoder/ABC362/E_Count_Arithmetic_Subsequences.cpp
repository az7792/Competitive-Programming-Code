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
vector<ll> dp(100, 0);
vector<bool> vis(81, 0);
void dfs(int n, vector<pair<vector<ll>, vector<ll>>> &g)
{
    for (auto &v : g[n].first)
    {
        if (vis[v])
            continue;
        vis[v] = 1;
        dfs(v, g);
    }
    g[n].second[1] = 1;
    for (int i = 2; i <= 80; ++i)
    {
        for (auto &v : g[n].first)
        {
            g[n].second[i] += g[v].second[i - 1];
            g[n].second[i] %= MOD;
        }
    }
}
void get(vector<pii> a)
{
    vector<pair<vector<ll>, vector<ll>>> g(90);
    for (auto [u, v] : a)
    {
        g[u].first.push_back(v);
    }
    for (int i = 1; i <= 80; ++i)
    {
        g[i].second = vector<ll>(81, 0);
    }

    for (int i = 1; i <= 80; ++i)
        vis[i] = 0;

    for (int i = 1; i <= 80; ++i)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        dfs(i, g);
    }
    for (int i = 1; i <= 80; ++i)
    {
        for (int j = 2; j <= 80; ++j)
        {
            dp[j] += g[i].second[j];
            dp[j] %= MOD;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    map<ll, vector<pii>> mp;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            mp[a[j] - a[i]].push_back(pii(i, j));
    for (auto [x, y] : mp)
    {
        get(y);
    }
    dp[1] = n;
    for (int i = 1; i <= n; ++i)
        cout << dp[i] << " ";
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
