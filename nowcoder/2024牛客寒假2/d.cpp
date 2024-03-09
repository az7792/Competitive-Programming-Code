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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll>> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i].first >> a[i].second;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    vector<ll> dis(n + 1, 1e18);
    dis[k] = 0;
    Q.push({0, k});
    while (!Q.empty())
    {
        pair<ll, ll> tmp = Q.top();
        Q.pop();
        if (tmp.first > dis[tmp.second])
            continue;
        for (auto [x, y] : a)
        {
            if (tmp.first + y < dis[(tmp.second - 1 + x) % n + 1])
            {
                dis[(tmp.second - 1 + x) % n + 1] = tmp.first + y;
                Q.push({tmp.first + y, (tmp.second - 1 + x) % n + 1});
            }
        }
    }

    if (dis[n] == 1e18)
        dis[n] = -1;
    cout << dis[n] << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
