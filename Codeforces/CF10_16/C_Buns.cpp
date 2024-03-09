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
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 2, 0), c(m + 2, 0), b(m + 2, 0), d(m + 2, 0);
    cin >> c[1] >> d[1];
    a[1] = 1e3;
    b[1] = 1;
    for (int i = 2; i <= m + 1; ++i)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= m + 1; ++i)
    {
        vector<int> vec;
        int x = 1, s = a[i] / b[i];
        while (s >= x)
        {
            vec.push_back(x);
            s -= x, x *= 2;
        }
        if (s > 0)
            vec.push_back(s);
        for (auto v : vec)
            for (int j = n; j >= v * c[i]; --j)
                dp[j] = max(dp[j], dp[j - v * c[i]] + v * d[i]);
    }
    cout << dp[n];
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