#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define FAST {ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


vector<int>G[MAX];
int dep[MAX], fa[MAX][30];
void dfs(int p, int pre)
{
    dep[p] = dep[pre] + 1;
    fa[p][0] = pre;
    for (auto v : G[p])
        if (v != pre)
            dfs(v, p);
}
int LCA(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x]>dep[y])
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
    int n;
    cin >> n;
    G[1].emplace_back(0);
    for (int i = 1, a, b; i < n; ++i)
    {
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs(1, 0);
    for (int j = 1; j < 30; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][ j-1];
    
}