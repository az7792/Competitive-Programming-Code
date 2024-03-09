#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<vector<int>> G;
vector<int> dp;
vector<int> num;
void DFS(int p, int fa)
{
    num[p] = 1;
    for (auto v : G[p])
    {
        if (v != fa)
        {
            DFS(v, p);
            num[p] += num[v];
        }
    }
}
void dfs(int p, int fa)
{
    vector<int> tmp;
    for (auto v : G[p])
        if (v != fa)
            dfs(v, p), tmp.push_back(v);
    if (tmp.size() == 1)
        dp[p] = num[tmp.back()] - 1;
    else if (tmp.size() == 2)
        dp[p] = max(num[tmp[0]] - 1 + dp[tmp[1]], num[tmp[1]] - 1 + dp[tmp[0]]);
    else
        dp[p] = 0;
}
void solve()
{
    G.clear();
    dp.clear();
    dp.clear();
    int n;
    cin >> n;
    G.resize(n + 1);
    dp.resize(n + 1, 0);
    num.resize(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1, 0);
    dfs(1, 0);
    cout << dp[1] << endl;
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