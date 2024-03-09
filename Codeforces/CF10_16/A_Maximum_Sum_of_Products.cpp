#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 5e3 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<vector<ll>> dp(MAX + 2, vector<ll>(MAX + 2, 0));
vector<ll> a(MAX + 2, 0), b(MAX + 2, 0), c(MAX + 2, 0);
ll dfs(int x, int y)
{
    if (dp[x][y] != 0)
        return dp[x][y];
    dp[x][y] = dfs(x + 1, y - 1) + (a[x] - a[y]) * b[y] + (a[y] - a[x]) * b[x];
    return dp[x][y];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i], c[i] += c[i - 1] + a[i] * b[i];
    for (int i = 1; i <= n; ++i)
        dp[i][i] = c[n];
    for (int i = 1; i < n; ++i)
        dp[i][i + 1] = c[n] + (a[i] - a[i + 1]) * b[i + 1] + (a[i + 1] - a[i]) * b[i];
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            ans = max(dfs(i, j), ans);
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