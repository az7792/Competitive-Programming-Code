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
    int n;
    vector<ll> D;
    vector<ll> a;
    BIT(int N)
    {
        n = N;
        D.resize(n + 1, 0);
        a.resize(n + 1, 0);
    }
    int lowbit(int x)
    {
        return x & (-x);
    }
    void add(int x, ll v)
    {
        a[x] = v;
        while (x <= n)
        {
            D[x] = max(v, D[x]);
            x += lowbit(x);
        }
    }
    ll query(int l, int r)
    {
        ll res = 0;
        while (r >= l)
        {
            int tmp = r - lowbit(r) + 1;
            if (tmp >= l)
            {
                res = max(res, D[r]);
                r -= lowbit(r);
            }
            else
            {
                res = max(res, a[r]);
                r--;
            }
        }
        return res;
    }
};
void solve()
{
    ll n, d;
    cin >> n >> d;
    BIT bit(n);
    vector<ll> a(n + 1, 0), dp(n + 1, 0), sp(n + 1, 0);
    vector<pair<ll, ll>> b(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    auto c = a;
    sort(c.begin() + 1, c.end());
    sort(b.begin() + 1, b.end());
    for (int i = 1; i <= n; ++i)
    {
        sp[b[i].second] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int l, r;
        l = lower_bound(c.begin() + 1, c.end(), a[i] - d) - c.begin();
        r = upper_bound(c.begin() + 1, c.end(), a[i] + d) - c.begin() - 1;
        if (l > r)
            continue;
        dp[i] = bit.query(l, r) + 1;
        bit.add(sp[i], dp[i]);
    }
    cout << *max_element(dp.begin() + 1, dp.end());
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