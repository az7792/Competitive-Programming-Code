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
bool dp[MAX][3]; // L(0)---mid(1)---R(2)
void solve()
{
    int n;
    cin >> n;
    vector<int> G(n + 10, 0);
    vector<vector<int>> P(n + 10);
    for (int i = 1; i <= n; ++i)
        cin >> G[i];
    for (int i = 1; i <= n; ++i)
        if (i + G[i] <= n)
            P[i + G[i]].eb(i);
    dp[0][1] = dp[0][2] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (i - G[i] < 1)
            dp[i][2] = false;
        else if (dp[i - G[i] - 1][1] || dp[i - G[i] - 1][2])
            dp[i][2] = true;
        else
            dp[i][2] = false;
        bool f = 0;
        for (auto v : P[i])
        {
            if (dp[v - 1][1] || dp[v - 1][2])
            {
                f = 1;
                break;
            }
        }
        dp[i][1] = f;
    }
    if (dp[n][1] || dp[n][2])
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}