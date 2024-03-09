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
int h, w, n;
string str;
vector<vector<char>> g;
int ans = 0;
void dfs(int x, int y)
{
    for (auto v : str)
    {
        if (v == 'L')
        {
            y--;
        }
        else if (v == 'R')
        {
            y++;
        }
        else if (v == 'U')
        {
            x--;
        }
        else if (v == 'D')
        {
            x++;
        }
        if (x < 1 || y < 1 || x > h || y > w)
            return;
        if (g[x][y] == '#')
            return;
    }
    ans++;
}
void solve()
{
    g.clear();
    cin >> h >> w >> n;
    cin >> str;
    g.resize(h + 1, vector<char>(w + 1));
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cin >> g[i][j];
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
        {
            if (g[i][j] == '.')
                dfs(i, j);
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
