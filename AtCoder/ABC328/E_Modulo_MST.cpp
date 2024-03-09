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
ll w[30];
pii uv[30];
vector<int> G;
ll n, m, k, ans = 1e18;
int fa[10];
int Find(int p)
{
    if (p != fa[p])
        fa[p] = Find(fa[p]);
    return fa[p];
}
void dfs(int p, int la)
{
    if (la == 0)
    {
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        ll sum = 0;
        for (auto &v : G)
        {
            sum = (sum + w[v]) % k;
            int FA = Find(uv[v].first);
            int FB = Find(uv[v].second);
            if (FA != FB)
                fa[FA] = FB;
        }
        int ct = 0;
        for (int i = 1; i <= n; ++i)
            if (fa[i] == i)
                ct++;
        if (ct == 1)
            ans = min(ans, sum % k);
        return;
    }
    for (int i = p; i - 1 + la <= m; ++i)
    {
        G.push_back(i);
        dfs(i + 1, la - 1);
        G.pop_back();
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
        cin >> uv[i].first >> uv[i].second >> w[i];
    for (int i = 1; i + (n - 1) - 1 <= m; ++i)
    {
        G.push_back(i);
        dfs(i + 1, n - 2);
        G.pop_back();
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