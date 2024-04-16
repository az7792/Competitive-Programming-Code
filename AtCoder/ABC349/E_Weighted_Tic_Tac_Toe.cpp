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
ll g[3][3];
int vis[3][3];
bool dfs(int who)
{
    int ct0 = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ct0 += (vis[i][j] == 0 ? 0 : 1);
    if (ct0 == 9)
    {
        ll s1 = 0, s2 = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                s1 += (vis[i][j] == 1 ? g[i][j] : 0), s2 += (vis[i][j] == 2 ? g[i][j] : 0);
        if (who == 1)
            return s1 > s2;
        return s1 < s2;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (vis[i][0] == vis[i][1] && vis[i][1] == vis[i][2] && vis[i][0] != 0)
            return 0;
        if (vis[0][i] == vis[1][i] && vis[1][i] == vis[2][i] && vis[0][i] != 0)
            return 0;
    }

    if (vis[0][0] == vis[1][1] && vis[1][1] == vis[2][2] && vis[0][0] != 0)
        return 0;
    if (vis[0][2] == vis[1][1] && vis[1][1] == vis[2][0] && vis[0][2] != 0)
        return 0;

    bool res = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            if (vis[i][j] == 0)
            {
                vis[i][j] = who;
                res &= dfs((who == 1 ? 2 : 1));
                vis[i][j] = 0;
            }
        }
    return !res;
}
void solve()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> g[i][j];
    cout << (dfs(1) ? "Takahashi" : "Aoki");
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
