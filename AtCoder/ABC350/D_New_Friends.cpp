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
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<pii> tmp;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        tmp.push_back({a, b});
        dsu.Union(a, b);
    }
    map<int, ll> mp;
    for (int i = 1; i <= n; ++i)
        dsu.Find(i);
    for (auto [a, b] : tmp)
    {
        mp[dsu.fa[a]]++;
    }
    map<int, ll> dian;
    for (int i = 1; i <= n; ++i)
    {
        dian[dsu.Find(i)]++;
    }
    ll ans = 0;
    for (auto [x, y] : dian)
    {
        ans += ((y) * (y - 1)) / 2ll - mp[x];
    }
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
