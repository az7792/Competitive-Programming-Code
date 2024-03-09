#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 4e5 + 10;
const ll MOD = 998244353;
vector<int> g(MAX);
bool dfs(int l, int r)
{
    if (l > r)
        return true;
    if (g[l] < l || g[l] > r)
        return false;
    bool f = dfs(l + 1, g[l] - 1);
    f &= dfs(g[l] + 1, r);
    return f;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a] = b;
        g[b] = a;
    }
    bool f = dfs(2, g[1] - 1);
    f = (f && dfs(g[1] + 1, 2 * n));
    cout << (f ? "No" : "Yes");
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
