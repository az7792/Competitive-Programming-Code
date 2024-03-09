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
    vector<int> p(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i)
        cin >> p[i];
    vector<int> w;
    w.push_back(0);
    int tmp = p[1], ct = 1;
    for (int i = 2; i <= 2 * n; ++i)
    {
        if (p[i] < tmp)
            ct++;
        else
        {
            tmp = p[i];
            w.push_back(ct);
            ct = 1;
        }
    }
    vector<vector<int>> dp(w.size() + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < w.size(); ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (j - w[i] < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + w[i]);
        }
    }
    if (dp[w.size() - 1][n] == n)
        cout << "YES\n";
    else
        cout << "NO\n";
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