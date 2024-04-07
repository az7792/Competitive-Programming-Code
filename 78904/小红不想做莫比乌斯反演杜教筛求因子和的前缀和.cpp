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
void solve()
{
    ll n, m, p, x;
    cin >> n >> m >> p >> x;
    ll ans = 0;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= m; ++j)
        {
            ll a = (x - i * j);
            ll b = 2 * (j + i);
            if (a >= b && a % b == 0 && a / b >= 1 && a / b <= p)
                ans++;
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
