#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
void solve()
{
    vector<vector<int>> a(4, vector<int>(4));
    vector<vector<int>> vis(4, vector<int>(4, 0));
    vector<int> ok(10, 0);
    vector<int> aaa = {
        0,
        1,
        2,
        3,
        4,
        5,
        10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
        {
            cin >> a[i][j];
            ok[a[i][j]] = 1;
            if (a[i][j] == 0)
                vis[i][j] = 1;
        }
    int p;
    for (int i = 0; i <= 9; ++i)
        if (ok[i] == 0)
            p = i;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
        {
            if (a[i][j] == 0)
                a[i][j] = p;
        }
    for (int i = 0; i < 3; ++i)
    {
        int x, y;
        cin >> x >> y;
        cout << a[x][y] << endl;
    }
    int ans = 0, op;
    cin >> op;
    if (op <= 3)
        for (int i = 1; i <= 3; ++i)
            ans += a[op][i];
    else if (op <= 6)
        for (int i = 1; i <= 3; ++i)
            ans += a[i][op - 3];
    else if (op == 7)
    {
        for (int i = 1; i <= 3; ++i)
            ans += a[i][i];
    }
    else
    {
        ans += a[1][3] + a[2][2] + a[3][1];
    }
    cout << aaa[ans];
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
