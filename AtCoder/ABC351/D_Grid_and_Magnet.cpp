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
int n, m;
struct Node
{
    int x, y, sp;
    Node(int X, int Y, int S)
    {
        x = X, y = Y, sp = S;
    }
};

void solve()
{
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
    auto ok = [&g](int x, int y) -> bool
    {
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (g[nx][ny] == '#')
                return true;
        }
        return false;
    };

    vector<pii> e;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (g[i][j] == '#')
                continue;
            if (g[i][j] == '.' && ok(i, j))
                ans = max(1, ans);
            else if (vis[i][j] == 0)
            {
                // bfs
                queue<pii> Q;
                int Mp = 1;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    int x = Q.front().first;
                    int y = Q.front().second;
                    Q.pop();
                    for (int k = 0; k < 4; ++k)
                    {
                        int nx = x + tx[k];
                        int ny = y + ty[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (g[nx][ny] == '#')
                            continue;
                        if (vis[nx][ny] == 1)
                            continue;
                        vis[nx][ny] = 1;
                        Mp++;
                        if (ok(nx, ny))
                            e.push_back({nx, ny});
                        else
                            Q.push({nx, ny});
                    }
                }
                ans = max(ans, Mp);
                for (auto [x, y] : e)
                    vis[x][y] = 0;
                e.clear();
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
