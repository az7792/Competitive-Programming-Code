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
struct Node
{
    int a, b, d, sp, lift;
    bool operator<(Node const &A) const
    {
        return a < A.a;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> tr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> tr[i].first >> tr[i].second;
        tr[i].first++;
        tr[i].second++;
    }
    sort(tr.begin() + 1, tr.end());
    BIT bit(n);
    vector<Node> M;
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        b++, c++, d++;
        M.push_back({a, b, d, i, 0});
        M.push_back({c, b, d, i, 1});
    }
    sort(all(M));
    vector<int> ans(m + 1, 0);
    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (p < M.size() && tr[i].first > M[p].a)
        {
            int tmp = bit.query(M[p].d) - bit.query(M[p].b - 1);
            ans[M[p].sp] += M[p].lift == 0 ? -tmp : tmp;
            p++;
        }
        bit.add(tr[i].second, 1);
    }
    for (; p < M.size(); ++p)
    {
        int tmp = bit.query(M[p].d) - bit.query(M[p].b - 1);
        ans[M[p].sp] += M[p].lift == 0 ? -tmp : tmp;
    }
    for (int i = 1; i <= m; ++i)
    {
        cout << ans[i] << endl;
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
