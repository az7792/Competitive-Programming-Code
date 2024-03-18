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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(m);
    BIT bit(n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        bit.add(i, a[i]);
        bit.add(i + 1, -a[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        b[i]++;
    }
    for (int i = 0; i < m; ++i)
    {
        ll tmp = bit.query(b[i]);
        bit.add(b[i], -tmp);
        bit.add(b[i] + 1, tmp);
        ll len = min(n - b[i], tmp);
        bit.add(b[i] + 1, 1);
        bit.add(b[i] + len + 1, -1);

        tmp -= len;

        ll cen = tmp / n;
        ll yu = (tmp % n == 0 ? 0 : tmp % n);
        bit.add(1, cen);
        bit.add(n + 1, -cen);

        if (yu >= 1)
        {
            bit.add(1, 1);
            bit.add(yu + 1, -1);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << bit.query(i) << " ";
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
