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
    string s, t;
    vector<bitset<5>> dp;
    vector<bool> vis;
    vector<bool> ok;
    int ct;
    cin >> n >> m >> s >> t;
    if (m == 1)
    {
        bool ans = true;
        for (auto v : s)
            if (v != t[0])
                ans = false;
        cout << (ans ? "Yes" : "No");
        return;
    }
    if (n <= m)
    {
        cout << (s == t ? "Yes" : "No");
        return;
    }
    dp.resize(n, bitset<5>(0));
    vis.resize(n, 0), ct = n;
    ok.resize(n, 0);
    if (s[0] != t[0])
    {
        cout << "No";
        return;
    }
    dp[0][0] = 1;
    int l = 0, r = -1;
    for (int i = 1; i < n; ++i)
    {
        if (vis[i])
        {
            dp[i] = dp[i - 1] << 1;
            dp[i][0] = 1;
        }
        else
        {
            for (int j = 0; j < m - 1; ++j)
                if (dp[i - 1][j] == 1 && s[i] == t[j + 1])
                    dp[i][j + 1] = 1;
            dp[i][0] = (s[i] == t[0]);
        }

        if (dp[i][m - 1] == 1 && ok[i] == 0)
        {
            r = i;
            l = i - m + 1;
            while (l <= r)
            {
                if (ok[l] == 1)
                {
                    l++;
                    continue;
                }
                ok[l] = 1;
                for (int j = 0; j < m; ++j)
                {
                    if (dp[l][j] == 0)
                    {
                        ok[l] = 0;
                        break;
                    }
                }
                if (vis[l] == 0)
                {
                    vis[l] = 1;
                    ct--;
                }
                if (l != 0)
                    dp[l] = dp[l - 1] << 1;
                dp[l][0] = 1;
                if (dp[l][m - 1])
                {
                    ok[l] = 1;
                    for (int j = 0; j < m; ++j)
                    {
                        if (dp[l][j] == 0)
                        {
                            ok[l] = 0;
                            break;
                        }
                    }
                    l = l - m + 1;
                }
                else
                    l++;
            }
        }
    }
    cout << (ct == 0 ? "Yes" : "No");
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