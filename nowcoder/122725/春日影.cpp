#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
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
     int n, m;
     cin >> n >> m;
     struct Node
     {
          ll p, w;
     };
     struct Qnode
     {
          ll p, d;
     };
     struct cmp
     {
          bool operator()(const Qnode &a, const Qnode &b) const
          {
               return a.d > b.d;
          }
     };

     vector<vector<Node>> g(n + 1);
     for (ll i = 1, u, v, w; i <= m; ++i)
     {
          cin >> u >> v >> w;
          g[v].push_back({u, w});
          g[u].push_back({v, w});
     }

     vector<ll> dis(n + 1, 1e18);

     priority_queue<Qnode, vector<Qnode>, cmp> Q;

     for (int i = 1; i <= n; ++i)
     {
          sort(all(g[i]), [&](const Node &a, const Node &b)
               { return a.w < b.w; });
     }

     dis[1] = 0;
     Q.push({1, 0});
     while (!Q.empty())
     {
          auto tmp = Q.top();
          Q.pop();
          if (tmp.d < dis[tmp.p])
               continue;

          for (auto v : g[tmp.p])
          {
               ll W = min(2 * g[tmp.p][0].w, v.w);
               if (tmp.d + W < dis[v.p])
               {
                    dis[v.p] = tmp.d + W;
                    Q.push({v.p, dis[v.p]});
               }
          }
     }

     cout << (dis[n] == 1e18 ? -1 : dis[n]);
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