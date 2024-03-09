#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
vector<vector<char>> str;
int n;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
struct Node
{
    int x, y, a, b;
};

bool vis[70][70][70][70];
int d[70][70][70][70];
void solve()
{
    cin >> n;
    str.resize(n + 2);
    str[0].resize(n + 2);
    str[n + 1].resize(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        str[i].resize(n + 2);
        for (int j = 1; j <= n; ++j)
        {
            cin >> str[i][j];
        }
    }
    for (int i = 0; i <= n + 1; ++i)
        str[0][i] = '#';
    for (int i = 0; i <= n + 1; ++i)
        str[n + 1][i] = '#';

    for (int i = 0; i <= n + 1; ++i)
        str[i][0] = '#';
    for (int i = 0; i <= n + 1; ++i)
        str[i][n + 1] = '#';

    pii a = {0, 0}, b;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (str[i][j] == 'P')
            {
                if (a == pair<int, int>(0, 0))
                    a = {i, j};
                else
                    b = {i, j};
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d[i][j][i][j] = 1e9;
    vis[a.first][a.second][b.first][b.second] = 1;
    int ans = 1e9;
    queue<Node> Q;
    Q.push({a.first, a.second, b.first, b.second});
    while (!Q.empty())
    {
        a = {Q.front().x, Q.front().y};
        b = {Q.front().a, Q.front().b};
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            pii na = {a.first + tx[i], a.second + ty[i]};
            pii nb = {b.first + tx[i], b.second + ty[i]};
            if (str[na.first][na.second] == '#')
                na = a;
            if (str[nb.first][nb.second] == '#')
                nb = b;
            if (na == a && nb == b)
                continue;
            if (vis[na.first][na.second][nb.first][nb.second] == 1)
                continue;
            vis[na.first][na.second][nb.first][nb.second] = 1;            
            d[na.first][na.second][nb.first][nb.second] = d[a.first][a.second][b.first][b.second] + 1;
            Q.push({na.first, na.second, nb.first, nb.second});
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans = min(ans, d[i][j][i][j]);
    if (ans == 1e9)
        ans = -1;
    cout << ans;
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
