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
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    vector<ll> dp(n + 10, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll Max = 0;
    for (int i = n; i >= 1; --i)
    {
        dp[i] = max({Max, a[i] + Max, a[i] + dp[i + 1]}); // Max[i+2,n]
        if (i == 1)
            break;
        Max = max(Max, dp[i + 1]);
    }
    cout << max(Max, dp[1]) << endl;
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