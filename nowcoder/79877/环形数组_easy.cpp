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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>(m, 0));
    int f = 0, x = 0, y = 0, ct = 1;
    while (1)
    {
        if (ct == n * m + 1)
            break;
        g[x][y] = ct++;
        int nx = x + tx[f];
        int ny = y + ty[f];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] != 0)
        {
            f = (f + 1) % 4;
            nx = x + tx[f];
            ny = y + ty[f];
        }
        x = nx, y = ny;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << g[i][j] << " ";
        cout << endl;
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
