#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 5e5 + 10;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<string, pii> mp;
map<pii, int> smp;
vector<vector<vector<bool>>> ff;
int n, m, sx, sy, ex, ey;
bool f;
int dfs(int x, int y, pii d)
{
    if (x == ex && y == ey)
        return 0;
    if (ff[x][y][smp[d]])
    {
        f = false;
        return 0;
    }
    ff[x][y][smp[d]] = true;

    int nx, ny;
    bool f1 = true, f2 = true;

    if (x + d.first == 0)
        nx = 2;
    else if (x + d.first == n + 1)
        nx = n - 1;
    else
        nx = x + d.first, f1 = false;

    if (y + d.second == 0)
        ny = 2;
    else if (y + d.second == m + 1)
        ny = m - 1;
    else
        ny = y + d.second, f2 = false;
    int ans = f1 || f2 ? 1 : 0;
    d.first = nx - x;
    d.second = ny - y;
    return ans + dfs(nx, ny, d);
}
void solve()
{
    string d;
    f = true;
    cin >> n >> m >> sx >> sy >> ex >> ey >> d;
    ff.clear();
    ff.resize(n + 1, vector<vector<bool>>(m + 1, vector<bool>(4, false)));
    int ans = dfs(sx, sy, mp[d]);
    if (!f)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));
    mp["DR"] = {1, 1};
    mp["DL"] = {1, -1};
    mp["UR"] = {-1, 1};
    mp["UL"] = {-1, -1};
    smp[{1, 1}] = 0;
    smp[{1, -1}] = 1;
    smp[{-1, 1}] = 2;
    smp[{-1, -1}] = 3;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}