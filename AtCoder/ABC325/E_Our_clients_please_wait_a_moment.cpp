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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<ll>> d(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> d[i][j];
    vector<ll> len1(n + 1, 1e18);
    vector<ll> lenn(n + 1, 1e18);
    priority_queue<Node> Q;
    len1[1] = 0, lenn[n] = 0;
    Q.push({1, 0});
    while (!Q.empty())
    {
        Node t = Q.top();
        Q.pop();
        if (len1[t.x] < t.len)
            continue;
        for (int i = 1; i <= n; ++i)//邻接表直接auto v:G[t.x]
        {
            if (len1[i] > t.len + d[t.x][i] * a)
            {
                len1[i] = t.len + d[t.x][i] * a;
                Q.push({i, len1[i]});
            }
        }
    }
    Q.push({n, 0});
    while (!Q.empty())
    {
        Node t = Q.top();
        Q.pop();
        if (lenn[t.x] < t.len)
            continue;
        for (int i = 1; i <= n; ++i)
        {
            if (lenn[i] > t.len + d[t.x][i] * b + c)
            {
                lenn[i] = t.len + d[t.x][i] * b + c;
                Q.push({i, lenn[i]});
            }
        }
    }
    ll ans = 1e18;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, len1[i] + lenn[i]);
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