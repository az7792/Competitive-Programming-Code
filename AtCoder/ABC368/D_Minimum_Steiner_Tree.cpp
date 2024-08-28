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
vector<vector<int>> g(MAX);
vector<bool> ok(MAX);
set<int> s;
pair<int, bool> dfs(int p, int fa)
{
    int sum = 0;
    bool have = 0;
    for (auto v : g[p])
    {
        if (v == fa)
            continue;
        pair<int, bool> tmp = dfs(v, p);
        sum += tmp.first;
        have |= tmp.second;
    }
    if (!have && s.find(p) == s.end())
        sum++;
    else
        have = 1;
    return pair<int, bool>(sum, have);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0, a, b; i < n - 1; ++i)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0, v; i < k; ++i)
    {
        cin >> v;
        s.insert(v);
    }
    cout << n - dfs(*s.begin(), 0).first;
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
