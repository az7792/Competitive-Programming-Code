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
void solve()
{
    ll n, q, x, y, a;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i)
        cin >> a, mp[a]++;
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        ll D = x * x - 4 * y;
        if (D < 0)
            cout << 0 << ' ';
        else
        {
            ll tmp = sqrt(D);
            ll x1 = (x + tmp) / 2;
            ll x2 = (x - tmp) / 2;
            if (tmp * tmp != D)
                cout << 0 << ' ';
            else if ((x + tmp) % 2 != 0 || (x - tmp) % 2 != 0)
                cout << 0 << ' ';
            else if (x1 == x2)
                cout << mp[x1] * (mp[x2] - 1) / 2 << " ";
            else
                cout << mp[x1] * mp[x2] << " ";
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