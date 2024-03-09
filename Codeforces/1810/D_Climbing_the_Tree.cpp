#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pll GetLR(ll a, ll b, ll n)
{
    if (n == 1)
        return pll(1, a);
    return pll((n - 2) * (a - b) + a + 1, (n - 1) * (a - b) + a);
}
ll GetN(ll a, ll b, ll h)
{
    if (h <= a)
        return 1;
    return 1 + (h - a + (a - b - 1)) / (a - b);
}
void solve()
{
    ll q, a, b, n, op;
    cin >> q;
    pll h = {1, 1e18};
    for (int i = 1; i <= q; ++i)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b >> n;
            pll tmp = GetLR(a, b, n);
            tmp.first = max(tmp.first, h.first);
            tmp.second = min(tmp.second, h.second);
            if (tmp.first <= tmp.second)
            {
                cout << 1 << ' ';
                h = tmp;
            }
            else
            {
                cout << 0 << ' ';
            }
        }
        else
        {
            cin >> a >> b;
            ll n1 = GetN(a, b, h.first);
            ll n2 = GetN(a, b, h.second);
            if (n1 == n2)
                cout << n1 << ' ';
            else
                cout << -1 << ' ';
        }
    }
    cout << endl;
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