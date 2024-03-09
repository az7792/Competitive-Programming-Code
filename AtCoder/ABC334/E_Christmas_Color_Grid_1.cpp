#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const ll MAX = 1e6 + 10;
const ll MOD = 998244353;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return POW((a * a) % MOD, b / 2) % MOD;
    else
        return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
int fa[MAX];
int n, m;
int Find(int p)
{
    if (p != fa[p])
        fa[p] = Find(fa[p]);
    return fa[p];
}
int get(int a, int b)
{
    return (a - 1) * m + b;
}
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
        fa[i] = i;
    vector<vector<char>> mp(n + 2, vector<char>(m + 2, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mp[i][j];
    ll ct = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int n1 = get(i, j);
            if (mp[i][j] == '#')
            {
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + tx[k];
                    int ny = j + ty[k];
                    if (nx <= 0 || ny <= 0 || nx > n || ny > m || mp[nx][ny] == '.')
                        continue;
                    int n2 = get(nx, ny);
                    int FA = Find(n1);
                    int FB = Find(n2);
                    if (FA != FB)
                    {
                        fa[FA] = FB;
                    }
                }
            }
            else
                ct++;
        }
    ll sumfa = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mp[i][j] == '#' && fa[get(i, j)] == get(i, j))
                sumfa++;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mp[i][j] == '.')
            {
                vector<int> FA;
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + tx[k];
                    int ny = j + ty[k];
                    if (nx <= 0 || ny <= 0 || nx > n || ny > m || mp[nx][ny] == '.')
                        continue;
                    FA.push_back(Find(get(nx, ny)));
                }
                set<int> S;
                for (auto v : FA)
                    S.insert(v);
                if (S.size() == 0)
                    ans += sumfa + 1;
                else
                    ans += sumfa - (S.size() - 1);
            }
    cout << ((ans % MOD) * POW(ct, MOD - 2)) % MOD;
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
