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
int fa[10010];
int n, k, m;
int Find(int x)
{
    if (x != fa[x])
        fa[x] = Find(fa[x]);
    return fa[x];
}
void solve()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= k; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (Find(u) != Find(v))
            fa[Find(u)] = Find(v);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (Find(u) != Find(v))
            fa[Find(u)] = Find(v), ans++;
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