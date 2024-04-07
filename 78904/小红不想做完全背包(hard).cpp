#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n + 1);
    vector<ll> dp(p + 1, 1e9);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] %= p;
        if (a[i] == 0)
            a[i] = p;
        dp[a[i]] = 1;
    }
    dp[p] = min(p, dp[p]);
    int q = 20;
    while (q--)
    {
        for (int i = 1; i <= p; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                ll num = i + a[j];
                num %= p;
                if (num == 0)
                    num = p;
                dp[num] = min(dp[num], dp[i] + 1);
            }
        }
    }
    cout << dp[p];
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
