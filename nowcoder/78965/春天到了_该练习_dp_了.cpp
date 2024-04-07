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
    int n, q;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // for (int i = 0; i <= n; ++i)
    //     for (int j = 0; j <= n; ++j)
    //     {
    //         if (i == 0)
    //             dp[i][j] = 0;
    //         else if (j == 0)
    //         {
    //             dp[i][j] = a[i] + dp[i - 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = a[i] + max(dp[i - 1][j], dp[i - 1][j - 1] + i * i);
    //         }
    //     }
    // for (int i = 0; i <= n; ++i)
    //     for (int j = 0; j <= n; ++j)
    //         cout << dp[i][j] << "\t\n"[j == n];
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    vector<ll> SSS(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
        SSS[i] = SSS[i - 1] + i * i;
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        ll SS = sum[r] - sum[l - 1];
        if (k == 0)
            cout << SS << "\n";
        else
        {
            int m = r - l + 1;
            // cout << SSS[m] << " ";SSS[m - k];
            //[m-k-1,m]
            cout << SS + SSS[m] - SSS[m - k] << "\n";
        }
    }
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
/*
0	0	0	0	0	0
1	2	2	2	2	2
3	7	8	8	8	8
6	15	19	20	20	20
10	26	35	39	40	40
15	40	56	65	69	70
*/