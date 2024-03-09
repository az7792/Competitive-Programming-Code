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
    ll a, b;
    cin >> a >> b;
    ll ans = 1e18;
    for (ll m = 1; m <= 1e5; ++m)
    {
        // ll tmp = (m - 1) + a / m + b / m + (a % m != 0) + (b % m != 0);
        ll tmp = (m - 1) + (a + m - 1) / m + (b + m - 1) / m;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
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