#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<ll> c, a, d, ans;
vector<bool> vis;
vector<ll> tmp;
void dfs(int p)
{
    if (vis[p])
    {
        int Min = 1e9 + 10;
        int p = 0;
        for (int i = 0; i < tmp.size(); ++i)
        {
            ll v = tmp[i];
            if (c[v] < Min)
            {
                Min = c[v];
                p = i;
            }
        }
        for (int i = (p + 1) % tmp.size(); i != p; i = (i + 1) % tmp.size())
        {
            ans.push_back(tmp[i]);
        }
        ans.push_back(tmp[p]);
        return;
    }
    vis[p] = true;
    tmp.push_back(p);
    dfs(a[p]);
}
void solve()
{
    c.clear();
    a.clear();
    d.clear();
    ans.clear();
    vis.clear();
    ll n;
    cin >> n;
    c.resize(n + 1);
    a.resize(n + 1);
    d.resize(n + 1);
    vis.resize(n + 1, false);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        d[a[i]]++;
    }
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    queue<ll> Q;
    for (int i = 1; i <= n; ++i)
        if (d[i] == 0)
            Q.push(i);
    while (!Q.empty())
    {
        ll tmp = Q.front();
        ans.push_back(tmp);
        vis[tmp] = true;
        d[a[tmp]]--;
        Q.pop();
        if (d[a[tmp]] == 0)
        {
            Q.push(a[tmp]);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (vis[i] == false)
        {
            tmp.clear();
            dfs(i);
        }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}