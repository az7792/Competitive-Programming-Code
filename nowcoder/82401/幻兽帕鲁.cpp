#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll dfs(ll l, ll r, ll x, ll s, ll sp)
{
    if (l == r)
        return s;
    ll mid = (l + r) / 2ll;
    if (x <= mid) // ou
    {
        return dfs(l, mid, x, s, sp * 2);
    }
    else // ji
    {
        return dfs(mid + 1, r, x, s + sp, sp * 2);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x;
        cin >> x;
        cout << dfs(0, (1ll << n) - 1, x, 0, 1) << endl;
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
