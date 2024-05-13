#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 1, 0, -1};
int ty[] = {1, 0, -1, 0};
map<char, int> mp;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n, vector<pair<char, int>>(m, {'1', 0}));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j].first;
    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        char ff;
        cin >> x >> y >> ff;
        x--, y--;
        if (g[x][y].first == '0' || g[x][y].first != '1')
            continue;
        int nx = x + tx[mp[ff]], ny = y + ty[mp[ff]];
        bool ok = 1;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny].first == '0' || g[nx][ny].first == '1') // 2
        {
            ok = 0;
        }
        else if (g[nx][ny].first == 'U' || g[nx][ny].first == 'L' || g[nx][ny].first == 'R' || g[nx][ny].first == 'D')
        {
            ok = 0;
        }
        if (ok == 1)
        {
            g[nx][ny].first -= 32;
        }
        else
        {
            g[x][y].first = ff;
            g[x][y].second = i;
            vector<pii> tmp;
            for (int j = 0; j < 4; ++j)
            {
                nx = x + tx[j];
                ny = y + ty[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny].first == '0' | g[nx][ny].first == '1')
                    continue;
                if (g[nx][ny].first == 'U' || g[nx][ny].first == 'L' || g[nx][ny].first == 'R' || g[nx][ny].first == 'D')
                    continue;
                int invx = nx + tx[mp[g[nx][ny].first]];
                int invy = ny + ty[mp[g[nx][ny].first]];
                if (invx == x && invy == y)
                    tmp.push_back({nx, ny});
            }
            sort(all(tmp), [&](pii A, pii B)
                 { return g[A.first][A.second].second > g[B.first][B.second].second; });
            if (tmp.size() >= 1)
            {
                g[x][y].first -= 32;
                g[tmp[0].first][tmp[0].second].first = '1';
                g[tmp[0].first][tmp[0].second].second = 0;
            }
        }

        //------
        // for (int ii = 0; ii < n; ++ii)
        // {
        //     for (int jj = 0; jj < m; ++jj)
        //     {
        //         if (g[ii][jj].first == '0')
        //             cout << 'X';
        //         else if (g[ii][jj].first == '1')
        //             cout << "O";
        //         else
        //             cout << g[ii][jj].first;
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        //------
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (g[i][j].first == '0')
                cout << 'X';
            else if (g[i][j].first == '1')
                cout << "O";
            else
                cout << g[i][j].first;
        }
        cout << endl;
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    // cin >> t;
    mp['r'] = 0;
    mp['d'] = 1;
    mp['l'] = 2;
    mp['u'] = 3;
    while (t--)
    {
        solve();
    }
    return 0;
}
