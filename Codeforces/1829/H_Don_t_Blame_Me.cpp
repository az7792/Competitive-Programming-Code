#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> G(n + 10, 0);
    vector<vector<ll>> dp(n + 10, vector<ll>(70, 0));
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    for (int i = 1; i <= n; ++i)
    {
        dp[i][G[i]] = 1;
        for (int j = 0; j <= 63; ++j)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            dp[i][j & G[i]] = (dp[i][j & G[i]] + dp[i - 1][j]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 63; ++i)
    {
        bitset<6> tmp(i);
        int ct = 0;
        for (int j = 0; j < 6; ++j)
            if (tmp[j] == 1)
                ct++;
        if (ct == k)
            ans = (ans + dp[n][i]) % MOD;
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