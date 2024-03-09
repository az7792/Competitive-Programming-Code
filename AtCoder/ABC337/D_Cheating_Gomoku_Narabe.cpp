#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> g(n + 2, vector<char>(m + 2));
    // vector<vector<pii>> cto(n + 2, vector<pii>(m + 2, {0, 0})); // f- s|
    // vector<vector<pii>> ctd(n + 2, vector<pii>(m + 2, {0, 0})); // f- s|
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> g[i][j];
    int ans = 1e9;
    int sum = 0, ctd = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum = ctd = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (g[i][j] == '.')
            {
                sum++;
                ctd++;
            }
            else if (g[i][j] == 'o')
            {
                sum++;
            }
            else
            {
                sum = ctd = 0;
            }
            if (sum == k)
            {
                ans = min(ans, ctd);
                if (g[i][j - k + 1] == '.')
                    ctd--;
                sum--;
            }
        }
    }
    sum = ctd = 0;
    for (int j = 1; j <= m; ++j)
    {
        sum = ctd = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (g[i][j] == '.')
            {
                sum++;
                ctd++;
            }
            else if (g[i][j] == 'o')
            {
                sum++;
            }
            else
            {
                sum = ctd = 0;
            }
            if (sum == k)
            {
                ans = min(ans, ctd);
                if (g[i - k + 1][j] == '.')
                    ctd--;
                sum--;
            }
        }
    }
    if (ans == 1e9)
        cout << -1;
    else
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
