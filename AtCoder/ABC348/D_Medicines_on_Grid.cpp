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
vector<vector<char>> g;
vector<vector<int>> num;
vector<vector<int>> step;
vector<vector<bool>> vis;
pii s, t;
int n, m;
void dfs(int x, int y)
{
    if (x == s.first && y == s.second)
    {
        cout << "Yes\n";
        exit(0);
    }
    vector<vector<bool>> VIS = vis;
    vector<pii> pos;
    queue<pii> Q;
    Q.push(pii(x, y));
    while (!Q.empty())
    {
        int xx = Q.front().first;
        int yy = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = xx + tx[i];
            int ny = yy + ty[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if (g[nx][ny] == '#' || vis[nx][ny] == 1 || VIS[nx][ny] == 1)
                continue;
            step[nx][ny] = min(step[nx][ny], step[xx][yy] + 1);
            if (step[nx][ny] <= num[nx][ny] && num[nx][ny] >= 1)
            {
                step[nx][ny] = 0;
                vis[nx][ny] = 1;
                pos.push_back(pii(nx, ny));
            }
            VIS[nx][ny] = 1;
            Q.push(pii(nx, ny));
        }
    }
    for (auto v : pos)
    {
        dfs(v.first, v.second);
    }
}
void solve()
{

    cin >> n >> m;
    g.clear(), num.clear(), step.clear(), vis.clear();
    g.resize(n + 1, vector<char>(m + 1));
    num.resize(n + 1, vector<int>(m + 1, 0));
    vis.resize(n + 1, vector<bool>(m + 1, 0));
    step.resize(n + 1, vector<int>(m + 1, 1e5));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> g[i][j];
            if (g[i][j] == 'S')
                s.first = i, s.second = j;
            if (g[i][j] == 'T')
                t.first = i, t.second = j;
        }

    int nn;
    cin >> nn;
    for (int i = 1; i <= nn; ++i)
    {
        int xx, yy;
        cin >> xx >> yy;
        cin >> num[xx][yy];
    }
    if (s == t)
    {
        cout << "Yes\n";
        return;
    }
    if (num[s.first][s.second] == 0)
    {
        cout << "No\n";
        return;
    }
    step[t.first][t.second] = 0;
    vis[t.first][t.second] = 1;
    dfs(t.first, t.second);
    cout << "No\n";
    return;
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
