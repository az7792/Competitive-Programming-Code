#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n + 1, 0);
    vector<ll> d(n + 1);
    vector<ll> D(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
        w[i] += w[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
        D[i] = d[i] + D[i - 1];
    }
    vector<ll> Max(n + 2, 0);
    for (int i = n; i >= 1; --i)
    {
        Max[i] = max({0ll, d[i], d[i] + Max[i + 1]});
    }
    ll ans = -1e18;
    for (int i = 1; i <= n; ++i)
    {
        int p = lower_bound(all(w), W + w[i - 1]) - w.begin();
        if(p>n)
            continue;
        ans = max(ans, D[p] - D[i - 1] + Max[p + 1]);
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
