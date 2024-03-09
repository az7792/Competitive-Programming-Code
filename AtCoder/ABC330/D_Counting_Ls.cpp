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
    vector<vector<char>> s(n + 2, vector<char>(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> s[i][j];
    vector<ll> col(n + 2, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            col[i] += (s[j][i] == 'o');
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        vector<ll> sum(n + 2, 0);
        for (int j = n; j >= 1; --j)
        {
            sum[j] += sum[j + 1];
            if (s[i][j] == 'o')
            {
                ans += sum[j];
                sum[j] += (col[j] - 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        vector<ll> sum(n + 2, 0);
        for (int j = 1; j <= n; ++j)
        {
            sum[j] += sum[j - 1];
            if (s[i][j] == 'o')
            {
                ans += sum[j];
                sum[j] += (col[j] - 1);
            }
        }
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
