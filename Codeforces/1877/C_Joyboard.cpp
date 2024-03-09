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
    ll n, m, k;
    cin >> n >> m >> k;
    if (k > 3)
        cout << 0 << endl;
    else if (m == 0)
        cout << (k == 1 ? 1 : 0) << endl;
    else if (n == 1)
    {
        if (k == 1)
            cout << 1 << endl;
        else if (k == 2)
            cout << m << endl;
        else
            cout << 0 << endl;
    }
    else
    {
        ll ans = 0;
        if (k == 1)
            cout << 1 << endl;
        else if (k == 2)
        {
            if (m <= n - 1)
            {
                cout << m << endl;
                return;
            }
            ans += n - 1;
            ll p = (m - n + 1) % n;
            ll num = (m - n + 1) / n;
            ans += num;
            if (p >= 1)
                ans++;
            cout << ans << endl;
        }
        else
        {
            if (m <= n - 1)
            {
                cout << 0 << endl;
                return;
            }
            ans = 0;
            ll p = (m - n + 1) % n;
            ll num = (m - n + 1) / n;
            ans += num * (n - 1);
            ans += max(0ll, p - 1);
            cout << ans << endl;
        }
    }
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}