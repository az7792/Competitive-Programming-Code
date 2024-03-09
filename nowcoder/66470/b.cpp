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
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n);
    vector<vector<ll>> sum(n);
    ll tmp;
    cin >> tmp;
    a[0].push_back(tmp);
    sum[0].push_back(tmp);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < 2 * i + 1; ++j)
        {
            cin >> tmp;
            a[i].push_back(tmp);
            tmp = -1e18;
            if (j >= 0 && j < a[i - 1].size())
                tmp = max(tmp, sum[i - 1][j]);
            if (j - 1 >= 0 && j - 1 < a[i - 1].size())
                tmp = max(tmp, sum[i - 1][j - 1]);
            if (j - 2 >= 0 && j - 2 < a[i - 1].size())
                tmp = max(tmp, sum[i - 1][j - 2]);
            sum[i].push_back(tmp + a[i][j]);
        }
    }
    ll ans = -1e18;
    ll mid = (sum[n - 1].size() - 1) / 2;
    for (int i = 0; i < sum[n - 1].size(); ++i)
        if (abs(i - mid) <= k)
            ans = max(ans, sum[n - 1][i]);
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