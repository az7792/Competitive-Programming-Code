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
struct Node
{
    ll x, len;
    bool operator<(const Node a) const
    {
        return len > a.len;
    }
};
void solve()
{
    ll n, a;
    cin >> n;
    vector<vector<ll>> d(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> d[i][j];
    vector<ll> dis(n + 1, 1e18);
    priority_queue<Node> Q;
    dis[1] = 0;
    Q.push({1, 0}); //[点的标号,起始点到当前点的距离]
    while (!Q.empty())
    {
        Node t = Q.top();
        Q.pop();
        if (dis[t.x] < t.len)
            continue;
        for (int i = 1; i <= n; ++i) // 邻接表直接auto v:G[t.x]
        {
            if (dis[i] > t.len + d[t.x][i]) // 如果通过t.x到达i点比直接到i点更优则更新
            {
                dis[i] = t.len + d[t.x][i];
                Q.push({i, dis[i]});
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << dis[i] << ' '; // 1到其他点的最短距离
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