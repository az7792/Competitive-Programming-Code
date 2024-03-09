#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll D[20][20];
bool f[20];
ll ans = 0, tmp = 0;
int n;
void dfs(int p)
{
    if (p > n)
    {
        ans = max(tmp, ans);
        return;
    }
    if (f[p])
    {
        dfs(p + 1);
        return;
    }
    for (int i = p; i <= n; ++i)
    {
        if (!f[i])
        {
            f[p] = true;
            f[i] = true;
            tmp += D[p][i];
            dfs(p + 1);
            f[p] = false;
            f[i] = false;
            tmp -= D[p][i];
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            cin >> D[i][j];
    dfs(1);
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}