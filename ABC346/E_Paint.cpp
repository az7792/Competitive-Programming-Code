#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
struct BIT
{
    int n;        // 数组长度[1,n]
    vector<ll> D; // 维护前缀和
    BIT(int N)
    {
        n = N;
        D.resize(n + 1);
    }
    int lowbit(int x)
    {
        return x & (-x);
    }
    void add(int x, ll v) // 在[x]加上v
    {
        while (x <= n)
        {
            D[x] += v;
            x += lowbit(x);
        }
    }
    ll query(int x) // 查询[1,x]的值
    {
        ll res = 0;
        while (x)
        {
            res += D[x];
            x -= lowbit(x);
        }
        return res;
    }
};
struct info
{
    ll t, a, x;
};

void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<info> g(q);
    vector<ll> ans(200001, 0);
    ans[0] = n * m;
    for (int i = 0; i < q; ++i)
        cin >> g[i].t >> g[i].a >> g[i].x;
    vector<bool> visr(n + 1, 0), visc(m + 1, 0);
    ll row = 0, col = 0;
    for (int i = g.size() - 1; i >= 0; --i)
    {
        int t = g[i].t, a = g[i].a, x = g[i].x;
        if (t == 1)
        {
            if (visr[a] == 0)
            {
                visr[a] = 1;
                ans[x] += m - col;
                ans[0] -= m - col;
                row++;
            }
        }
        else
        {
            if (visc[a] == 0)
            {
                visc[a] = 1;
                ans[x] += n - row;
                ans[0] -= n - row;
                col++;
            }
        }
    }
    vector<pair<ll, ll>> res;
    for (int i = 0; i <= 200000; ++i)
    {
        if (ans[i] > 0)
            res.push_back({i, ans[i]});
    }
    cout << res.size() << endl;
    for (auto v : res)
        cout << v.first << " " << v.second << endl;
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
