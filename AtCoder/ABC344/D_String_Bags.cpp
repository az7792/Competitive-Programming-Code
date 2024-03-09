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
    string t;
    cin >> t;
    t = "*" + t;
    int n;
    cin >> n;
    vector<vector<string>> g(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int m;
        cin >> m;
        g[i].resize(m);
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
    }
    vector<vector<int>> dp(n + 1, vector<int>(t.size() + 1, 2e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < t.size(); ++j)
        {
            // buyao
            dp[i][j] = dp[i - 1][j];
            for (auto v : g[i])
            {
                // yao
                bool f = 1;
                if (j - (int)v.size() < 0)
                {
                    continue;
                }
                else
                {
                    int ct = 0;
                    for (int a = j - v.size() + 1; a <= j; ++a)
                    {
                        if (t[a] != v[ct++])
                        {
                            f = 0;
                            break;
                        }
                    }
                }

                if (f)
                    dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - v.size()]);
            }
        }
    }
    if (dp[n][t.size() - 1] == 2e9)
        cout << -1;
    else
        cout << dp[n][t.size() - 1];
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
