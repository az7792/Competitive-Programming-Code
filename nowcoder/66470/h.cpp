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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<int> Max(n + 1, 0);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            Max[i] = max(Max[i], a[i][j]);
        }
    dp[1] = Max[1];
    int mmax = dp[1];
    for (int i = 2; i <= n; ++i)
    {
        if (i - k >= 1)
            dp[i] = max(Max[i] + mmax, dp[i - 1]);
        else
            dp[i] = dp[i - 1];
        mmax = max(mmax, dp[max(1, i - k + 1)]); //[1---i-k]
    }
    cout << *max_element(all(dp));
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