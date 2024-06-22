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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n + 1, 0), sum(n + 1, 0), SUM(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
        SUM[i] = SUM[i - 1] + (x[i] - x[i - 1]) * b;
        sum[i] = x[i] + sum[i - 1];
    }
    ll ans = 1e18;
    for (int i = 0; i <= n; ++i)
    {
        ll tmp = x[i] * a + SUM[i];
        ll N = sum[n] - sum[i] - x[i] * (n - i);
        N *= b;
        ans = min(ans, tmp + N);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}