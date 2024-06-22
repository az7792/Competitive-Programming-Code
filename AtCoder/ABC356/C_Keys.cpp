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
int n, m, k;
vector<int> c;
vector<char> r;
vector<vector<int>> g;
int ans = 0;
vector<int> a;
void dfs(int p)
{
    if (p == n + 1)
    {
        bool f = 1;
        for (int i = 1; i <= m; ++i)
        {
            int ct = 0;
            char ch = 'x';
            for (int j = 1; j <= c[i]; ++j)
            {
                if (a[g[i][j]] == 1)
                    ct++;
            }
            if (ct >= k)
                ch = 'o';
            if (ch != r[i])
            {
                f = 0;
                break;
            }
        }
        if (f)
            ans++;
        return;
    }
    a[p] = 0;
    dfs(p + 1);
    a[p] = 1;
    dfs(p + 1);
}
void solve()
{
    cin >> n >> m >> k;
    c.resize(m + 1, 0), r.resize(m + 1), g.resize(m + 1), a.resize(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> c[i];
        g[i].resize(c[i] + 1);
        for (int j = 1; j <= c[i]; ++j)
            cin >> g[i][j];
        cin >> r[i];
    }
    dfs(1);
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
