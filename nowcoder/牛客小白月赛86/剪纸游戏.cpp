#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
vector<string> s;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
int L, R, U, D, S, n, m;
void dfs(int x, int y)
{
    L = min(L, y);
    R = max(R, y);
    U = min(U, x);
    D = max(D, x);
    S++;
    s[x][y] = 0;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + tx[i];
        int ny = y + ty[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (s[nx][ny] == 0 || s[nx][ny] == '*')
            continue;
        dfs(nx, ny);
    }
}
void solve()
{
    int ans = 0;
    s.clear();
    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] != 0 && s[i][j] == '.')
            {
                D = U = i;
                L = R = j;
                S = 0;
                dfs(i, j);
                if (S == (D - U + 1) * (R - L + 1))
                    ans++;
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
