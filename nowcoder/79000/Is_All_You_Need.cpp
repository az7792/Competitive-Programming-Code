#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const ll MAX = 2e5 + 10;
const ll MOD = 998244353;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
struct Dij
{
    int n; //(1-n)
    vector<ll> dis;
    Dij(int N, int now, vector<vector<pair<ll, ll>>> &g) //<距离,点>
    {
        n = N;
        dis.resize(n + 1, -1e18);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
        dis[now] = 0;
        Q.push({0, now});
        while (!Q.empty())
        {
            pair<ll, ll> tmp = Q.top();
            Q.pop();
            if (dis[tmp.second] > tmp.first)
                continue;
            for (auto v : g[tmp.second])
            {
                if (dis[v.second] < tmp.first + v.first)
                {
                    dis[v.second] = tmp.first + v.first;
                    Q.push({dis[v.second], v.second});
                }
            }
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> r(n + 1, vector<ll>(m + 1));
    vector<vector<pair<ll, ll>>> g(n + 2);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> r[i][j];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int si;
            cin >> si;
            g[i].push_back({r[i][j], si});
        }
    }
    Dij dij(n + 1, 1, g);
    cout << dij.dis[n + 1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(nullptr));
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
