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
vector<vector<int>> g;
vector<ll> dp1, dp2;
void dfs(int p, int fa)
{
    dp1[p] = 1;
    for (auto v : g[p])
    {
        if (v == fa)
            continue;
        dfs(v, p);
        dp2[p] = (dp2[p] + dp1[v]) % MOD;
        dp1[p] = ((dp1[v] + 1) * dp1[p]) % MOD;
    }
}
void solve()
{
    g.clear(), dp1.clear(), dp2.clear();
    int n;
    cin >> n;
    g.resize(n + 1), dp1.resize(n + 1), dp2.resize(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + dp2[i]) % MOD;
    ans = (ans + dp1[1] + 1) % MOD;
    cout << ans << endl;
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
