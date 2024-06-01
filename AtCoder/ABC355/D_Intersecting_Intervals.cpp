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
    vector<pii> a(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        p[i] = a[i].second;
    }
    BIT bit(n);
    sort(p.begin() + 1, p.end());
    sort(a.begin() + 1, a.end());
    int pp = lower_bound(p.begin() + 1, p.end(), a[1].second) - p.begin();
    bit.add(pp, 1);
    ll ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        pp = lower_bound(p.begin() + 1, p.end(), a[i].first) - p.begin();
        ans += bit.query(n) - bit.query(pp - 1);
        bit.add(lower_bound(p.begin() + 1, p.end(), a[i].second) - p.begin(), 1);
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
