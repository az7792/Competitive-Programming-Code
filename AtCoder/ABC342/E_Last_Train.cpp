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
struct Node
{
    ll l, d, k, c, A, B;
};
vector<vector<Node>> g;
vector<ll> dis;
void dfs(int p)
{
    for (auto v : g[p])
    {
        ll l = v.l, d = v.d, k = v.k, c = v.c, A = v.A, B = v.B;
        ll tm = dis[p] - c;
        if (l > tm)
            continue;
        ll L = min((tm - l) / d, k - 1);
        if (l + L * d > dis[A])
        {
            dis[A] = l + L * d;
            dfs(A);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    dis.resize(n + 1, -1);
    for (int i = 0; i < m; ++i)
    {
        Node tmp;
        cin >> tmp.l >> tmp.d >> tmp.k >> tmp.c >> tmp.A >> tmp.B;
        g[tmp.B].push_back(tmp);
    }

    priority_queue<pair<ll, ll>> Q;
    Q.push({4e18, n}); // dis p
    dis[n] = 4e18;
    while (!Q.empty())
    {
        pair<ll, ll> t = Q.top();
        Q.pop();
        if (dis[t.second] > t.first)
            continue;
        for (auto &[l, d, k, c, A, B] : g[t.second])
        {
            // dis[A]
            ll tm = dis[t.second] - c;
            ll L = min((tm - l) / d, k - 1);
            if (dis[A] < l + L * d)
            {
                dis[A] = l + L * d;
                Q.push({dis[A], A});
            }
        }
    }

    for (int i = 1; i < n; ++i)
        if (dis[i] == -1)
            cout << "Unreachable\n";
        else
            cout << dis[i] << endl;
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
