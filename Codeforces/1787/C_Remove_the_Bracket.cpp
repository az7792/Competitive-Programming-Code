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
ll dp[MAX][2];
ll n, s;
ll Min(ll num)
{
    if (s + s >= num)
        return num - min(s, num);
    return s;
}
ll Max(ll num)
{
    return num - Min(num);
}
// ll Min(ll num)
// {
//     if (s >= num)
//         return 0;
//     return s;
// }
// ll Max(ll num)
// {
//      if (s >= num)
//         return num;
//     return num-s;
// }
void solve()
{
    cin >> n >> s;
    vector<ll> G(n + 10, 0);
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    dp[2][0] = G[1] * Min(G[2]) + Max(G[2]) * G[3];
    dp[2][1] = G[1] * Max(G[2]) + Min(G[2]) * G[3];
    for (int i = 3; i <= n - 1; ++i)
    {
        dp[i][0] = Max(G[i]) * G[i + 1]; // x最小
        dp[i][1] = Min(G[i]) * G[i + 1]; // x最大
        ll d = G[i] - Min(G[i]);
        dp[i][0] += min(dp[i - 1][0] - Max(G[i - 1]) * d, dp[i - 1][1] - Min(G[i - 1]) * d);
        d = G[i] - Max(G[i]);
        dp[i][1] += min(dp[i - 1][0] - Max(G[i - 1]) * d, dp[i - 1][1] - Min(G[i - 1]) * d);
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    s = 4;
    cerr << Min(6) << ' ' << Max(6) << endl;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}