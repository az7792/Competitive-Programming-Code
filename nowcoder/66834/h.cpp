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
ll tx[] = {0, 0, -1, 1};
ll ty[] = {-1, 1, 0, 0};
void solve()
{
    ll n, m, k;
    cin >> n >> m;
    map<pll, ll> mp;
    vector<vector<char>> G(n + 2, vector<char>(m + 2, '#'));
    vector<vector<ll>> f(n + 2, vector<ll>(m + 2, 1e18));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> G[i][j];
    cin >> k;
    while (k--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        mp[{x, y}] = z;
    }
    queue<pll> Q;
    Q.push({1, 1});
    f[1][1] = 0;
    while (!Q.empty())
    {
        pll t = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            if (G[t.first][t.second] == '.')
            {
                ll nx = t.first + tx[i];
                ll ny = t.second + ty[i];
                if (nx < 1 || ny < 1 || nx > n || ny > m)
                    continue;
                if (G[nx][ny] == '#' || f[nx][ny] <= f[t.first][t.second] + 1)
                    continue;
                f[nx][ny] = f[t.first][t.second] + 1;
                Q.push({nx, ny});
            }
            else if (G[t.first][t.second] == '*') //*
            {
                ll nx = t.first + tx[i] * mp[{t.first, t.second}];
                ll ny = t.second + ty[i] * mp[{t.first, t.second}];
                if (nx < 1 || ny < 1 || nx > n || ny > m)
                    continue;
                if (G[nx][ny] == '#' || f[nx][ny] <= f[t.first][t.second])
                    continue;
                f[nx][ny] = f[t.first][t.second];
                Q.push({nx, ny});
            }
        }
    }
    cout << (f[n][m] == 1e18 ? -1 : f[n][m]);
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
/*

pll t = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            if (G[t.first][t.second] == '.')
            {
                ll nx = t.first + tx[i];
                ll ny = t.first + ty[i];
                if (nx < 1 || ny < 1 || nx > n || ny > m)
                    continue;
                if (G[nx][ny] == '#' || f[nx][ny] <= f[t.first][t.second] + 1)
                    continue;
                f[nx][ny] = f[t.first][t.second] + 1;
                Q.push({nx, ny});
            }
            else if (G[t.first][t.second] == '*') //*
            {
                ll nx = t.first + tx[i] * mp[{t.first, t.second}];
                ll ny = t.second + ty[i] * mp[{t.first, t.second}];
                if (nx < 1 || ny < 1 || nx > n || ny > m)
                    continue;
                if (G[nx][ny] == '#' || f[nx][ny] <= f[t.first][t.second])
                    continue;
                f[nx][ny] = f[t.first][t.second];
                Q.push({nx, ny});
            }

        */