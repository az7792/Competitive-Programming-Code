#include <bits/stdc++.h> //Ji
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 1e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
vector<vector<int>> g;
vector<ll> a;
void dfs(int p, int ct, int fa, map<int, ll> &mp)
{

    if (a[p] <= 0)
    {
        for (auto &v : g[p])
            if (v != fa)
                dfs(v, ct + 1, p, mp);
        if (a[p] < 0)
            mp[ct] += -a[p];
    }
    else
    {
        map<int, ll> tmp;

        for (auto &v : g[p])
            if (v != fa)
                dfs(v, ct + 1, p, tmp);

        for (auto &v : tmp)
        {
            if (a[p] == 0)
                mp[v.first] += v.second;
            else if (v.second > a[p])
            {
                if (v.second - a[p] > 0)
                    mp[v.first] += v.second - a[p];
                a[p] = 0;
            }
        }

        tmp.clear();
    }
}
void solve()
{
    int n;
    cin >> n;
    g.clear();
    g.resize(n + 1);
    a.resize(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int aa, bb;
        cin >> aa >> bb;
        g[aa].push_back(bb);
        g[bb].push_back(aa);
    }

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    map<int, ll> A1; //<time,pos>
    dfs(1, 0, 0, A1);
    ll ans = 0, tmp = 0;
    for (auto v : A1)
        ans = max(ans, v.second);
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
