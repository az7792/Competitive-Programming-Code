#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;

vector<int> vs[100100];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1, 0);
    vector<int> ans(n + 100, -1);
    vector<bool> vis(n + 10, 0);
    for (int i = 2; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        vs[u].push_back(v);
        vs[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    int res;
    ans[1] = 0;
    while (!q.empty())
    {
        int cnt = q.front();
        q.pop();
        for (auto it : vs[cnt])
        {
            if (vis[it])
            {
                continue;
            }
            int tmp = it;
            vis[it] = 1;
            q.push(it);
            vs[it].push_back(cnt);
            vis[it] = 1;
            res = ans[cnt] + 1;
            while (ans[tmp] == -1)
            {
                ans[tmp] = res;
                tmp = p[tmp];
                if (!vis[tmp])
                {
                    vis[tmp] = 1;
                    q.push(tmp);
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    return;
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