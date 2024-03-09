#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    string str;
    cin >> str;
    int n = str.size();
    str = "*" + str;
    if (str.find('m') != str.npos || str.find('w') != str.npos)
    {
        cout << "0";
        return;
    }
    vector<vector<ll>> dp(2, vector<ll>(n + 1, 0)); // 0bu 1yao
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (str[i] == str[i - 1] && (str[i] == 'u' || str[i] == 'n'))
        {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
            dp[1][i] = (dp[0][i - 2] + dp[1][i - 2]) % MOD;
        }
        else
        {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
            dp[1][i] = 0;
        }
    }
    cout << (dp[0][n] + dp[1][n]) % MOD;
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