#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<double> a(n + 1, 0), p(n + 1, 0);
    vector<double> dp(n + 1, 1e18);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    double ans = n;
    for (int i = 0; i < n; ++i)
    {
        double w = p[i] / 1e5;
        double l = 1.0 - p[i] / 1e5;
        if (i == a[i])
        {
            if (w == 0)
                dp[i] = 1e18;
            else
                dp[i] = 1 / w;
        }
        else
        {
            dp[i] = w + l * (dp[a[i]] + 1);
            double tmp = (i - a[i]);
            dp[i] = min(dp[i], (1 + (i - a[i])) / w - tmp);
        }
        dp[i] = min(dp[i], 1.0 * n - i);
        ans = min(ans, i + dp[i]);
    }
    printf("%.12lf\n", ans);
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