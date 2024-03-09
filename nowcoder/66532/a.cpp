#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string ans[2] = {"Bob", "Alice"};
vector<vector<int>> win(101, vector<int>(101, -1));
void dfs(int x, int y)
{
    if (win[x][y] != -1)
        return;
    if (x - 1 >= 0 && (!(x - 1 == 0 && y == 0)))
    {
        dfs(x - 1, y);
        if (win[x - 1][y] == 0)
        {
            win[x][y] = 1;
            return;
        }
    }
    if (x - 2 >= 0 && (!(x - 2 == 0 && y == 0)))
    {
        dfs(x - 2, y);
        if (win[x - 2][y] == 0)
        {
            win[x][y] = 1;
            return;
        }
    }
    if (x - 5 >= 0 && (!(x - 5 == 0 && y == 0)))
    {
        dfs(x - 5, y);
        if (win[x - 5][y] == 0)
        {
            win[x][y] = 1;
            return;
        }
    }
    for (int i = 1; y - i >= 0; ++i)
        if ((!(x == 0 && y - i == 0)))
        {
            dfs(x, y - i);
            if (win[x][y - i] == 0)
            {
                win[x][y] = 1;
                return;
            }
        }
    win[x][y] = 0;
}
void init()
{
    for (int i = 0; i <= 100; ++i)
        if (i % 3 == 0)
        {
            win[i][0] = 0;
            for (int j = 1; j <= 100; ++j)
                win[i][j] = 1;
        }
        else
            win[i][0] = 1;
    for (int i = 0; i <= 100; ++i)
    {
        for (int j = 0; j <= 100; ++j)
            dfs(i, j);
    }
}
void solve()
{
    ll m, n;
    cin >> m >> n;
    if (m % 3 == 0)
    {
        if (n == 0)
            cout << ans[0] << endl;
        else
            cout << ans[1] << endl;
    }
    else
    {
        if ((m + 1) % 3 == 0)
        {
            cout << ans[n != 2] << endl;
        }
        else
        {
            cout << ans[n != 1] << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    // init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}