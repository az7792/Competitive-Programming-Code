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
    ll ans = 0;
    vector<vector<char>> G(n + 1, vector<char>(m + 1));
    vector<vector<pll>> num(n + 1, vector<pll>(m + 1, {0, 0}));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> G[i][j];
            if (G[i][j] == '#')
            {
                num[i][j].first = num[i][j - 1].first + 1;   // L
                num[i][j].second = num[i - 1][j].second + 1; // U
            }
            ans += (num[i][j].first * num[i][j].first) + (num[i][j].second * num[i][j].second);
        }
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