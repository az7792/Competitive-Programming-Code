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
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    //[x-t[0]+1,x]
    vector<vector<ll>> dp(x + 1, vector<ll>(n, 0));
    // dp[i][j] 第i秒正好开始播放歌曲j的概率
    for (int j = 0; j < n; ++j)
        dp[0][j] = 1 * POW(n, MOD - 2);
    for (int i = 1; i <= x; ++i)
    {
        ll tmp = 0;
        for (int k = 0; k < n; ++k)
        {
            if (i - t[k] >= 0)
                tmp = (tmp + (dp[i - t[k]][k] * dp[0][0]) % MOD) % MOD;
        }
        for (int j = 0; j < n; ++j)
        {
            dp[i][j] = tmp;
        }
    }
    ll ans = 0;
    for (int i = max(0, x - t[0] + 1); i <= x; ++i)
    {
        ans = (ans + dp[i][0]) % MOD;
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