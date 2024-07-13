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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        ll _1, _2, _3;
        cin >> _1 >> _2 >> _3;
        g[_1].push_back({_2, _3});
        g[_2].push_back({_1, _3});
    }
    vector<ll> dis(n + 1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push({a[1], 1});
    dis[1] = a[1];
    while (!Q.empty())
    {
        pair<ll, ll> tmp = Q.top();
        Q.pop();
        if (dis[tmp.second] < tmp.first)
            continue;
        for (auto [x, y] : g[tmp.second])
        {
            if (tmp.first + a[x] + y < dis[x])
            {
                dis[x] = tmp.first + a[x] + y;
                Q.push({dis[x], x});
            }
        }
    }
    for (int i = 2; i <= n; ++i)
        cout << dis[i] << " ";
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
