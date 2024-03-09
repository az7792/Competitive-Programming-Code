#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<vector<ll>> ans(1001000, vector<ll>(10, 0));
int get(ll a)
{
    int res = 0;
    while (a != 0)
    {
        res += a % 10;
        a /= 10;
    }
    return res;
}
void init()
{
    // for (ll n = 0; n <= 1000; ++n)
    // {
    //     int ct = 0;
    //     for (int i = 0; i <= n; ++i)
    //         for (int j = 0; j <= n; ++j)
    //             for (int k = 0; k <= n; ++k)
    //             {
    //                 if (i + j + k == n && get(i) + get(j) + get(k) == get(n))
    //                     ct++;
    //             }
    //     cout <<ct << " \t";
    //     if ((n + 1) % 10 == 0)
    //         cout << endl;
    // }
    ans[0] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
    int now = 0, x, y;
    for (int i = 1; i <= 100001; ++i)
    {
        x = (i - 1) * 10, y = 0;
        for (int j = 0; j < 10; ++j) // 0 - 9
        {
            ans[x][y + j] = ans[now][y + j];
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 9; ++j) // 1- 9
        {
            ans[x][y + j] = ans[x - 1][y + j] * 3;
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 8; ++j) // 2- 9
        {
            ans[x][y + j] = ans[x - 1][y + j] * 2;
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 7; ++j) // 3- 9
        {
            ans[x][y + j] = ans[x - 1][y + j] + ans[x - 2][y + j] + ans[x - 3][y + j];
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 6; ++j) // 4- 9
        {
            ans[x][y + j] = ans[x - 1][y + j] + ans[x - 2][y + j] - ans[x - 4][y + j];
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 5; ++j) // 5- 9
        {
            ans[x][y + j] = ans[x - 1][y + j] + ans[x - 3][y + j];
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 4; ++j) // 6- 9
        {
            ans[x][y + j] = ans[x - 2][y + j] + ans[x - 3][y + j] + ans[x - 5][y + j];
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 3; ++j) // 7- 9
        {
            ans[x][y + j] = ans[x - 2][y + j] + ans[x - 3][y + j];
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 2; ++j) // 8- 9
        {
            ans[x][y + j] = ans[x - 3][y + j] + ans[x - 4][y + j] + ans[x - 5][y + j] - ans[x - 8][y + j];
            ans[x + j][y] = ans[x][y + j];
        }

        x++, y++;
        for (int j = 0; j < 1; ++j) // 9- 9
        {
            ans[x][y + j] = ans[x - 1][y + j] + ans[x - 6][y + j];
            ans[x + j][y] = ans[x][y + j];
        }
        now++;
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << ans[n / 10][n % 10] << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    init();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
