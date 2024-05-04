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
struct DSU
{
    vector<int> fa;
    DSU(int n) // 最大编号
    {
        fa.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            fa[i] = i;
    }
    int Find(int p)
    {
        if (p != fa[p])
            fa[p] = Find(fa[p]);
        return fa[p];
    }
    void Union(int a, int b)
    {
        int FA = Find(a), FB = Find(b);
        fa[FA] = FB;
    }

    bool isUnion(int a, int b)
    {
        int FA = Find(a), FB = Find(b);
        return FA == FB;
    }
};
struct Node
{
    vector<int> s;
    ll c;
};
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<Node> node(m);
    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> k >> node[i].c;
        for (int j = 0, tmp; j < k; ++j)
        {
            cin >> tmp;
            node[i].s.emplace_back(tmp);
        }
    }
    sort(all(node), [](Node &a, Node &b)
         { return a.c < b.c; });
    ll ans = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 1; j < node[i].s.size(); ++j)
        {
            // node[i].s[0] node[i].s[j]
            if (!dsu.isUnion(node[i].s[0], node[i].s[j]))
            {
                dsu.Union(node[i].s[0], node[i].s[j]);
                ans += node[i].c;
            }
        }
    }
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dsu.fa[i] == i)
            ct++;
    }
    if (ct != 1)
        cout << -1;
    else
        cout << ans;
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
