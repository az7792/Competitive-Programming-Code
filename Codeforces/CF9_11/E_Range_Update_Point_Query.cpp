#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<ll> ct;
ll n;
ll lowbit(ll x)
{
    return x & (-x);
}
void add(int p, ll v)
{
    while (p <= n)
    {
        ct[p] += v;
        p += lowbit(p);
    }
}
ll query(int p)
{
    ll res = 0;
    while (p >= 1)
    {
        res += ct[p];
        p -= lowbit(p);
    }
    return res;
}
void solve()
{
    ct.clear();
    ll q;
    cin >> n >> q;
    ct.resize(n + 2, 0);
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            add(l, 1);
            add(r + 1, -1);
        }
        else
        {
            int x;
            cin >> x;
            ll t = min(query(x), 5ll);
            ll tmp = a[x];
            while (t--)
            {
                ll tt = 0;
                while (tmp != 0)
                {
                    tt += tmp % 10;
                    tmp /= 10;
                }
                tmp = tt;
            }
            cout << tmp << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
