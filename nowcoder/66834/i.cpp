#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> G[MAX];
int dep[MAX], fa[MAX][30];
ll sum[MAX];
bool f[MAX];
struct Node
{
    int x, y, z;
};
void dfs(int i, int pre)
{
    dep[i] = dep[pre] + 1;
    fa[i][0] = pre;
    for (auto v : G[i])
    {
        if (!f[v])
        {
            f[v] = true;
            dfs(v, i);
        }
    }
}

void dfs1(int p)
{
    for (auto v : G[p])
    {
        dfs1(v);
        sum[p] += sum[v];
    }
}
void dfs2(int p)
{
    for (auto v : G[p])
    {
        sum[v] += sum[p];
        dfs2(v);
    }
}
int LCA(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[y] < dep[x])
    {
        x = fa[x][(int)log2(dep[x] - dep[y])];
    }
    if (x == y)
        return x;
    for (int j = 29; j >= 0; --j)
        if (fa[x][j] != fa[y][j])
            x = fa[x][j], y = fa[y][j];
    return fa[x][0];
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<Node> tmp(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> tmp[i].x >> tmp[i].y >> tmp[i].z;
        G[tmp[i].x].push_back(tmp[i].y);
        G[tmp[i].y].push_back(tmp[i].x);
    }
    f[1] = true;
    dfs(1, 0);
    for (int j = 1; j < 30; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    while (m--)
    {
        int x, y;
        ll add;
        cin >> x >> y >> add;
        int FA = LCA(x, y);
        sum[x] += add;
        sum[y] += add;
        sum[FA] -= 2 * add;
    }
    for (int i = 1; i <= n; ++i)
        G[i].clear();
    for (int i = 1; i <= n; ++i)
        G[fa[i][0]].push_back(i);
    dfs1(0);
    for (auto &[x, y, z] : tmp)
    {
        if (fa[x][0] == y)
            sum[x] += z;
        else
            sum[y] += z;
    }
    dfs2(0);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int FA = LCA(x, y);
        cout << sum[x] + sum[y] - 2 * sum[FA] << endl;
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