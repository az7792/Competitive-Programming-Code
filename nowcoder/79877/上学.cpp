#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
int tx[] = {0, 1, 0, -1};
int ty[] = {1, 0, -1, 0};
struct Node
{
    ll a, b, c;
};

vector<vector<int>> g;
vector<Node> num;
ll ans = 0;
void dfs(int x, ll sp, int fa)
{
    num[x].c = 1;
    for (auto v : g[x])
    {
        if (v != fa)
        {
            dfs(v, sp + 1, x);
            num[x].a += num[v].a + num[v].b;
            num[x].b += num[v].b + num[v].c;
            num[x].c += num[v].c;
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    g.resize(n + 1);
    num.resize(n + 1, {0, 0, 0});
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = (n) * (n - 1) * (n - 2) / 6ll;
    dfs(1, 1, 0);
    cout << ans - num[1].a;
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
