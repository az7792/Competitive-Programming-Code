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
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    BIT bit(n);
    BIT zero(n);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    b = a;
    sort(b.begin() + 1, b.end());
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int p = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        ans += b[p] * zero.query(p) - bit.query(p);
        zero.add(p, 1);
        bit.add(p, b[p]);
    }
    cout << ans;
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
