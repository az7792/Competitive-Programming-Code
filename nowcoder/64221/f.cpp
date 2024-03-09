#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<ll> num;
vector<ll> a;
ll n, q;
ll lowbit(ll x)
{
    return x & (-x);
}
ll query(ll l, ll r, ll x)
{
    ll res = x;
    while (l <= r)
    {
        if (r - lowbit(r) >= l)
        {
            res |= num[r];
            r -= lowbit(r);
        }
        else
        {
            res |= a[r];
            r--;
        }
    }
    return res;
}
void add(ll p, ll v)
{
    while (p <= n)
    {
        num[p] |= v;
        p += lowbit(p);
    }
}
void solve()
{
    cin >> n >> q;
    num.resize(n + 1, 0);
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        add(i, a[i]);
    }
    while (q--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        cout << query(l, r, x) << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}