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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (i + a[i] + 1 <= n)
            dp[i] = min(dp[i + 1] + 1, dp[i + a[i] + 1]);
        else
            dp[i] = dp[i + 1] + 1;
    }
    cout << dp[0] << endl;
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