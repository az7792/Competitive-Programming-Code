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
    int n, q;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<vector<int>> num(n + 1, vector<int>(31, 0));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        for (int j = 0; j < 31; ++j)
            num[i][j] = num[i - 1][j] + (a[i] >> j & 1);
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        vector<int> tmp(31, 0);
        for (int i = 0; i < 31; ++i)
            tmp[i] = num[r][i] - num[l - 1][i];
        int len = r - l + 1;
        int ans = 0;
        for (int i = 0; i < 31; ++i)
        {
            int zero = len - tmp[i];
            if (tmp[i] < zero)
                ans += (1 << i);
        }
        cout << ans << endl;
    }
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