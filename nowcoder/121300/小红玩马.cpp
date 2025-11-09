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
     int n, m, k;
     cin >> n >> m >> k;
     int x[3], y[3];
     cin >> x[1] >> y[1];
     cin >> x[2] >> y[2];

     if (x[1] == x[2] && y[1] == y[2])
     {
          if (k % 2 == 1)
          {
               cout << "No";
               return;
          }

          for (int i = 0; i < 8; ++i)
          {
               int nx = x[1] + tx[i];
               int ny = y[1] + ty[i];
               if (nx < 1 || ny < 1 || nx > n || ny > m)
                    continue;
               cout << "Yes\n";
               for (int j = 1; j <= k / 2; ++j)
               {
                    cout << nx << " " << ny << "\n"
                         << x[1] << " " << y[1] << endl;
               }
               return;
          }
          cout << "No\n";
          return;
     }

     vector<vector<pii>> g0(n + 1, vector<pii>(m + 1, {0, 0}));
     vector<vector<pii>> g1(n + 1, vector<pii>(m + 1, {0, 0}));
     vector<vector<pair<bool, bool>>> vis(n + 1, vector<pair<bool, bool>>(m + 1, {0, 0}));
     struct Node
     {
          int x, y, z;
     };
     queue<Node> Q;

     vis[x[1]][y[1]] = {1, 1};
     Q.push({x[1], y[1], 0});
     while (!Q.empty())
     {
          Node tmp = Q.front();
          Q.pop();

          if (tmp.x == x[2] && tmp.y == y[2])
               continue;
          
          if(tmp.z > k) continue;

          for (int i = 0; i < 8; ++i)
          {
               int nx = tmp.x + tx[i];
               int ny = tmp.y + ty[i];
               if (nx < 1 || ny < 1 || nx > n || ny > m)
                    continue;

               if ((tmp.z + 1) % 2 == 0)
               {
                    if (vis[nx][ny].first)
                         continue;
                    vis[nx][ny].first = 1;
                    g0[nx][ny] = {tmp.x, tmp.y};
               }
               else
               {
                    if (vis[nx][ny].second)
                         continue;
                    vis[nx][ny].second = 1;
                    g1[nx][ny] = {tmp.x, tmp.y};                    
               }

               Q.push({nx, ny, tmp.z + 1});
          }
     }

     if (vis[x[2]][y[2]] == pair<bool, bool>{0, 0})
     {
          cout << "No\n";
          return;
     }

     vector<pii> ans1;
     pii ed = {x[2], y[2]};
     if (vis[ed.first][ed.second].second)
     {
          bool ji = 1;
          while (1)
          {
               if (ed == pii{x[1], y[1]})
                    break;
               ans1.push_back(ed);
               ed = ji ? g1[ed.first][ed.second] : g0[ed.first][ed.second];
               ji = !ji;
          }
          reverse(all(ans1));

          if ((k - ans1.size()) % 2 == 0)
          {
               cout << "Yes\n";

               for (int i = 1; i <= (k - ans1.size()) / 2; ++i)
               {
                    cout << ans1.front().first << " " << ans1.front().second << "\n"
                         << x[1] << " " << y[1] << "\n";
               }

               for (auto v : ans1)
                    cout << v.first << " " << v.second << "\n";

               return;
          }
     }

     ans1.clear();
     ed = {x[2], y[2]};
     if (vis[ed.first][ed.second].first)
     {
          bool ji = 0;
          while (1)
          {
               if (ed == pii{x[1], y[1]})
                    break;
               ans1.push_back(ed);
               ed = ji ? g1[ed.first][ed.second] : g0[ed.first][ed.second];
               ji = !ji;
          }
          reverse(all(ans1));
          if ((k - ans1.size()) % 2 == 0)
          {
               cout << "Yes\n";

               for (int i = 1; i <= (k - ans1.size()) / 2; ++i)
               {
                    cout << ans1.front().first << " " << ans1.front().second << "\n"
                         << x[1] << " " << y[1] << "\n";
               }

               for (auto v : ans1)
                    cout << v.first << " " << v.second << "\n";

               return;
          }
     }

     cout << "No";
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