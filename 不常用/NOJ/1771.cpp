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
map<ll, ll> mp;
int dp[MAX][30][4];
void solve()
{
    vector<int> G(MAX, 0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> G[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            for (int m = 1; m <= 3; ++m)
            {
                int a, b;
                if (m == 1)
                    a = 2, b = 3;
                else if (m == 2)
                    a = 1, b = 3;
                else
                    a = 1, b = 2;
                dp[i][j][m] = max({dp[i - 1][j][m], dp[i - 1][j - 1][a], dp[i - 1][j - 1][b]});
                if (m == G[i])
                    dp[i][j][m]++;
                ans = max(ans, dp[i][j][m]);
            }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*




*/