#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = max({dp[n][0], dp[n][1], dp[n][2]});
        
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
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
