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

int g[11][11];
vector<pii> a;
vector<bool> f;
int N, n, m;
int sum = 0;
bool ok(int x, int y, int l, int r)
{
    l--;
    r--;
    for (int i = x; i <= x + l; ++i)
        for (int j = y; j <= y + r; ++j)
            if (g[i][j] == 1)
                return 0;
    return 1;
}
void P()
{
    return;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << g[i][j];
        cout << endl;
    }
    cout << sum;
    cout << endl;
}
void zero(int x, int y, int l, int r)
{
    sum -= l * r;
    l--;
    r--;
    for (int i = x; i <= x + l; ++i)
        for (int j = y; j <= y + r; ++j)
            g[i][j] = 0;
    P();
}

void one(int x, int y, int l, int r)
{

    sum += l * r;
    if (sum == n * m)
    {
        cout << "Yes";
        exit(0);
    }
    l--;
    r--;
    for (int i = x; i <= x + l; ++i)
        for (int j = y; j <= y + r; ++j)
            g[i][j] = 1;
    P();
}
void dfs(int x, int y)
{
    if (g[x][y])
    {
        dfs(x, y + 1);
        return;
    }
    if (y == m + 1)
    {
        dfs(x + 1, 1);
        return;
    }
    if (x == n + 1)
    {
        cout << "Yes1";
        exit(0);
    }
    for (int i = 0; i < N; ++i)
    {
        if (!f[i])
        {
            f[i] = 1;
            // if (x == 1 && y == 1 && i == 1)
            // {
            //     cout << 1;
            // }
            if (x + a[i].first - 1 <= n && y + a[i].second - 1 <= m)
            {
                if (ok(x, y, a[i].first, a[i].second))
                {
                    one(x, y, a[i].first, a[i].second);
                    dfs(x, y + 1);
                    zero(x, y, a[i].first, a[i].second);
                }
            }

            if (x + a[i].second - 1 <= n && y + a[i].first - 1 <= m)
            {
                if (ok(x, y, a[i].second, a[i].first))
                {
                    one(x, y, a[i].second, a[i].first);
                    dfs(x, y + 1);
                    zero(x, y, a[i].second, a[i].first);
                }
            }
            f[i] = 0;
        }
    }
}
void solve()
{
    cin >> N >> n >> m;
    a.resize(N);
    f.resize(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> a[i].first >> a[i].second;
    dfs(1, 1);
    cout << "No";
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
