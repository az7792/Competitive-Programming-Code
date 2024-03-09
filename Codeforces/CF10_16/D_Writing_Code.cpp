#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 500 + 10;
ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll dp[2][MAX][MAX];
void solve()
{
    ll n, m, b, MOD;
    cin >> n >> m >> b >> MOD;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int y = i & 1;
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k <= b; ++k)
                dp[y][j][k] = 0;
        dp[y][0][0] = 1;
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= b; ++k)
                if (k - a[i] < 0)
                    dp[y][j][k] = dp[y ^ 1][j][k];
                else
                    dp[y][j][k] = (dp[y][j - 1][k - a[i]] + dp[y ^ 1][j][k]) % MOD;
    }
    ll ans = 0;
    for (int i = 0; i <= b; ++i)
        ans = (ans + dp[n & 1][m][i]) % MOD;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
