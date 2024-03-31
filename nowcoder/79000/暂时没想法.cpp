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
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (!dsu.isUnion(a, b))
            dsu.Union(a, b);
    }
    if (n == 1)
    {
        cout << "YES\n0\n";
        return;
    }
    int ct = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
        if (dsu.fa[i] == i)
        {
            ct++;
            mp[i] = ct - 1;
        }
    if (ct == 1)
    {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> g(ct);
    for (int i = 1; i <= n; ++i)
        g[mp[dsu.Find(i)]].push_back(i);
    // for (int i = 0; i < ct; ++i)
    // {
    //     for (auto v : g[i])
    //         cout << v << " ";
    //     cout << endl;
    // }
    cout << "YES\n";
    cout << n - 1 << endl;
    for (int i = 1; i < ct; ++i)
    {
        for (auto v : g[i])
        {
            cout << v << " " << g[0][0] << endl;
        }
    }
    for (int i = 1; i < g[0].size(); ++i)
    {
        cout << g[0][i] << " " << g[1][0] << endl;
    }
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
