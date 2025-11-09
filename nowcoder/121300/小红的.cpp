#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {1, 1, -1, -1, 2, -2, 2, -2};
int ty[] = {2, -2, 2, -2, 1, 1, -1, -1};
ll MOD = 1e9 + 7;
// ll MOD = 998244353;

template <typename T>
std::istream &operator>>(std::istream &_in, std::vector<T> &_a)
{
    for (auto &v : _a)
        _in >> v;
    return _in;
}

template <typename T>
std::ostream &operator<<(std::ostream &_out, std::vector<T> &_a)
{
    if (!_a.empty())
        _out << _a[0];
    for (size_t i = 1; i < _a.size(); ++i)
        _out << " " << _a[i];
    return _out;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v; i <= n - 1; ++i)
    {
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<array<int, 10>> dp(n + 1, array<int, 10>{});
    map<pii, array<int, 10>> mp;

    function<void(int, int)> dfs = [&](int p, int fa)
    {
        dp[p][0] = 1;
        for (auto v : g[p])
        {
            if (v == fa)
                continue;
            dfs(v, p);
            auto &tmp = p < v ? mp[{p, v}] : mp[{v, p}];
            tmp[0] = 1;
            for (int i = 1; i <= 9; ++i)
            {
                dp[p][i] += dp[v][i - 1];
                tmp[i] = dp[v][i - 1];
            }
        }
    };

    function<void(int, int)> dfs2 = [&](int p, int fa)
    {
        auto &tmp = p < fa ? mp[{p, fa}] : mp[{fa, p}];
        if (fa != 0)
            dp[p][1]++;
        for (int i = 2; i <= 9; ++i)
        {
            dp[p][i] += dp[fa][i - 1] - tmp[i - 1];
        }
        for (auto v : g[p])
        {
            if (v == fa)
                continue;
            dfs2(v, p);
        }
    };

    dfs(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; ++i)
        cout << dp[i][9] << " ";
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