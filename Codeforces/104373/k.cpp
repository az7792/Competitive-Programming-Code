#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<int> fa;
vector<bool> vis;
vector<int> ans;
vector<vector<int>> G;
int End;
int Find(int p)
{
    if (p != fa[p])
        fa[p] = Find(fa[p]);
    return fa[p];
}
bool f;
void dfs(int p)
{
    if (p == End)
    {
        f = false;
        return;
    }
    for (auto v : G[p])
    {
        if (!vis[v])
        {
            vis[v] = true;
            ans.push_back(v);
            dfs(v);
            if (!f)
                return;
            ans.pop_back();
        }
    }
}
void solve()
{
    f = true;
    G.clear();
    vis.clear();
    ans.clear();
    int n, m;
    cin >> n >> m;
    vis.resize(n + 1, 0);
    G.resize(n + 1);
    fa.clear();
    fa.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        fa[i] = i;
    map<pii, int> mp;
    vector<pii> a(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].second < a[i].first)
            swap(a[i].first, a[i].second);
        mp[a[i]] = i;
    }
    for (int i = 1; i <= m; ++i)
    {

        int F1 = Find(a[i].first);
        int F2 = Find(a[i].second);
        if (F1 == F2)
        {
            ans.push_back(i);
            ans.push_back(a[i].first);
            End = a[i].second;
            vis[a[i].first] = true;
            dfs(a[i].first);
            for (int j = 1; j < ans.size() - 1; ++j)
            {
                if (ans[j] <= ans[j + 1])
                    ans[j] = mp[{ans[j], ans[j + 1]}];
                else
                    ans[j] = mp[{ans[j + 1], ans[j]}];
            }
            ans.pop_back();
            sort(all(ans));
            for (int i = 0; i < ans.size(); ++i)
                cout << ans[i] << " \n"[i == ans.size() - 1];
            return;
        }
        else
        {
            G[a[i].first].push_back(a[i].second);
            G[a[i].second].push_back(a[i].first);
            fa[F1] = F2;
        }
    }
    cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
