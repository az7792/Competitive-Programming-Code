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
    ll n, c, sum = 0, S;
    cin >> n >> c;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    c--;
    if (c < 0)
    {
        c = -c;
        for (int i = 1; i <= n; ++i)
            a[i] = -a[i];
    }

    vector<ll> dp(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = a[i];
        dp[i] = max(dp[i - 1] + a[i], dp[i]);
    }
    S = *max_element(all(dp));
    cout << sum + S * c;
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
