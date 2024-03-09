#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<ll, ll>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
ll n;      // 数组长度[1,n]
ll D[MAX]; // 维护前缀和
ll lowbit(ll x)
{
    return x & (-x);
}
void add(ll x, ll v) // 在[x]加上v
{
    while (x <= n)
    {
        D[x] += v;
        x += lowbit(x);
    }
}
ll query(ll x) // 查询[1,x]的值
{
    ll res = 0;
    while (x)
    {
        res += D[x];
        x -= lowbit(x);
    }
    return res;
}
void solve()
{
    ll m;
    cin >> n >> m;
    for (ll i = 0; i <= n; ++i)
        D[i] = 0;
    vector<ll> x(m + 1);
    for (ll i = 1; i <= m; ++i)
        cin >> x[i];
    vector<pii> num(m + 1);
    for (ll i = 1; i < m; ++i)
    {
        if (x[i + 1] < x[i])
        {
            ll nx = x[i + 1] + n;
            num[i].second = nx - x[i];
            num[i].first = x[i] - x[i + 1];
            ll v = abs(num[i].first - num[i].second);
            if (num[i].first < num[i].second)
            {
                add(x[i + 1], v);
                add(x[i], -v);
            }
            else if (num[i].first > num[i].second)
            {
                add(x[i], v);
                add(n + 1, -v);
                add(1, v);
                add(x[i + 1], -v);
            }
        }
        else
        {
            num[i].second = x[i + 1] - x[i];
            ll nx = x[i + 1] - n;
            num[i].first = x[i] - nx;
            ll v = abs(num[i].first - num[i].second);
            if (num[i].first < num[i].second)
            {
                add(x[i + 1], v);
                add(n + 1, -v);
                add(1, v);
                add(x[i], -v);
            }
            else if (num[i].first > num[i].second)
            {
                add(x[i], v);
                add(x[i + 1], -v);
            }
        }
    }
    ll sum = 0;
    for (ll i = 1; i < m; ++i)
        sum += min(num[i].first, num[i].second);
    vector<ll> tmp(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        tmp[i] = query(i);
    }
    cout << sum + *min_element(tmp.begin() + 1, tmp.begin() + n + 1);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
