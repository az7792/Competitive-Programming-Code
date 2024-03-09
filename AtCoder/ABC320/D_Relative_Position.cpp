#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct Node
{
    ll p, x, y;
};
vector<pll> ans;
vector<bool> ok;
vector<vector<Node>> G;
void dfs(int PP)
{
    for (auto &[p, x, y] : G[PP])
    {
        if (!ok[p])
        {
            ok[p] = true;
            ans[p].first = ans[PP].first + x;
            ans[p].second = ans[PP].second + y;
            dfs(p);
        }
    }
}
void solve()
{
    ans.clear();
    G.clear();
    ok.clear();
    ll n, m;
    cin >> n >> m;
    ans.resize(n + 1);
    G.resize(n + 1);
    ok.resize(n + 1, false);
    for (int i = 1; i <= m; ++i)
    {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        G[a].push_back({b, x, y});
        G[b].push_back({a, -x, -y});
    }
    ans[1] = {0, 0};
    ok[1] = true;
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        if (ok[i])
            cout << ans[i].first << ' ' << ans[i].second << endl;
        else
            cout << "undecidable\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
