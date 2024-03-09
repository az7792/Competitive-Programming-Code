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
void solve()
{
    int n, m, k, a, b;
    cin >> n >> m >> k;
    vector<vector<bool>> g(n + 2, vector<bool>(n + 2, 0));
    vector<vector<bool>> vis(n + 2, vector<bool>(n + 2, 0));
    vector<pii> tmp;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a >> b;
        tmp.push_back({a, b});
        g[a][b] = 1;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        a = tmp[i].first, b = tmp[i].second;
        vis[a][b] = 1;
        ans += 4;
        for (int i = 0; i < 4; ++i)
        {
            int nx = a + tx[i];
            int ny = b + ty[i];
            if (vis[nx][ny])
                ans--;
        }
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
