#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pll> xy(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> xy[i].first >> xy[i].second;
    ll ans = abs(xy[a].first - xy[b].first) + abs(xy[a].second - xy[b].second);
    ll l1 = 1e18, l2 = 1e18;
    for (int i = 1; i <= k; ++i)
    {
        l1 = min(l1, abs(xy[a].first - xy[i].first) + abs(xy[a].second - xy[i].second));
        l2 = min(l2, abs(xy[i].first - xy[b].first) + abs(xy[i].second - xy[b].second));
    }
    cout << min(ans, l1 + l2) << endl;
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
