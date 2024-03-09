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
int s[MAX];
bool vis[MAX];
vector<pii> G[MAX];
void dfs(int p)
{
    for (auto &[x, y] : G[p])
    {
        if (!vis[x])
        {
            vis[x] = 1;
            s[x] = s[p] - y;
            dfs(x);
        }
    }
}
void solve()
{
    int n, m, q, a, b, c, y;
    cin >> n >> s[1] >> m >> q;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, -c});
    }
    vis[1] = true;
    dfs(1);
    while (q--)
    {
        cin >> y;
        if (s[y] == 0)
            cout << "?\n";
        else
            cout << s[y] << endl;
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
