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
vector<int> vis;
vector<vector<int>> G;
bool dfs(int p, int la)
{
    for (auto v : G[p])
    {
        if (vis[v] == -1)
        {
            vis[v] = vis[p] + 1;
            return dfs(v, p);
        }
        else
        {
            if (v != la)
                return ((vis[p] - vis[v] + 1) % 2 == 0);
        }
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vis.clear();
    G.clear();
    vis.resize(n + 1, -1);
    vector<pii> a(n);
    G.resize(n + 1);
    map<int, int> mmp;
    bool f = true;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        G[a[i].first].push_back(a[i].second);
        G[a[i].second].push_back(a[i].first);
        if (a[i].first == a[i].second)
            f = false;
        mmp[a[i].first]++;
        mmp[a[i].second]++;
    }
    if (!f)
    {
        cout << "NO\n";
        return;
    }
    for (auto &[x, y] : mmp)
        if (y >= 3)
        {
            cout << "NO\n";
            return;
        }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == -1)
        {
            vis[i] = 1;
            bool ok = dfs(i, 0);
            if (!ok)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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