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
    ll d;
    cin >> d;
    ll ans = 1e18;
    for (ll x = 0; x <= 1e6; ++x)
    {
        if (x * x >= d)
            ans = min(ans, x * x - d);
        else
        {
            ll D = d - x * x;
            ll tmp = sqrt(D);
            for (ll i = max(0ll, tmp - 1); i <= tmp + 1; ++i)
            {
                ans = min(ans, abs(i * i - D));
            }
        }
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
