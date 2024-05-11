#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e8;
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
    vector<ll> a(n + 2), sum(n + 2, 0), b(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    vector<pair<ll, ll>> info(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        info[i].first = a[i];
        info[i].second = i;
    }
    sort(info.begin() + 1, info.begin() + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        b[info[i].second] = i;
    }
    for (int i = n; i >= 1; --i)
        sum[i] = sum[i + 1] + a[i];
    ll ans = 0;
    BIT one(n);
    for (int i = 1; i <= n; ++i)
    {
        one.add(i, 1);
    }
    for (ll i = 1; i <= n; ++i)
    {
        ans += (a[i] * (n - i)) + sum[i + 1];
        //>=MOD - a[i] num
        ll tmp = MOD - a[i];
        int p = lower_bound(info.begin() + 1, info.begin() + n + 1, pair<ll, ll>(tmp, 0)) - info.begin();
        one.add(b[i], -1);
        ll num = one.query(n) - one.query(p - 1);
        ans -= num * MOD;
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
