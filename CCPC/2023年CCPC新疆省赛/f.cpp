#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n, m, k = 0;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<bool> ok(n + 1, false);
    vector<int> e(n + 1, 0);
    vector<bool> vis(n + 1, 0);
    vector<int> ans;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[v]++;
        G[u].push_back(v);
    }
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        ok[a[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (e[i] == 0 && ok[i] == false && vis[i] == false)
        {
            queue<int> Q;
            Q.push(i);
            while (!Q.empty())
            {
                int t = Q.front();
                Q.pop();
                ans.push_back(t);
                vis[t] = true;
                for (auto v : G[t])
                {
                    e[v]--;
                    if (e[v] == 0 && ok[v] == false)
                    {
                        Q.push(v);
                    }
                }
            }
        }
    }
    for (auto v : a)
    {
        vis[v] = true;
        if (e[v] != 0)
        {
            cout << -1;
            return;
        }
        for (auto V : G[v])
        {
            e[V]--;
        }
        ans.push_back(v);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (e[i] == 0 && vis[i] == false)
        {
            queue<int> Q;
            Q.push(i);
            while (!Q.empty())
            {
                int t = Q.front();
                Q.pop();
                ans.push_back(t);
                vis[t] = true;
                for (auto v : G[t])
                {
                    e[v]--;
                    if (e[v] == 0 && vis[v] == false)
                    {
                        Q.push(v);
                    }
                }
            }
        }
    }
    if (ans.size() == n)
        for (auto v : ans)
            cout << v << " ";
    else
        cout << -1;
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
