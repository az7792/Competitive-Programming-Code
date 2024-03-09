#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 1e1 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char a[MAX][MAX];
bool f[MAX][MAX];
int tx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ty[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int ans = 0;
int n, m;
void dfs(int x, int y)
{
    for (int i = 0; i < 8; ++i)
    {
        int nx = x + tx[i];
        int ny = y + ty[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m)
            continue;
        if (a[nx][ny] == '#' && !f[nx][ny])
        {
            f[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (!f[i][j] && a[i][j] == '#')
            {
                f[i][j] = true;
                ans++;
                dfs(i, j);
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