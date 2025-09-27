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
     vector<string> str(n);
     vector<vector<bool>> vis(n, vector<bool>(m, 0));
     vector<vector<int>> cnt(n, vector<int>(m, 0));
     for (int i = 0; i < n; ++i)
          cin >> str[i];
     struct Node
     {
          int x, y, ct;
          bool operator<(const Node &bb) const
          {
               if (ct == bb.ct)
               {
                    if (x == bb.x)
                    {
                         return y > bb.y;
                    }
                    return x > bb.x;
               }
               return ct > bb.ct;
          }
     };
     set<Node> s;
     for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
          {
               if (str[i][j] == '#')
               {
                    vis[i][j] = true;
                    continue;
               }
               int ct = 0;
               for (int k = 0; k < 4; ++k)
               {
                    int nx = i + tx[k];
                    int ny = j + ty[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                         continue;
                    if (str[nx][ny] == '#')
                         ct++;
               }
               cnt[i][j] = ct;
               if (ct <= 1)
               {
                    s.insert({i, j, ct});
               }
               else
               {
                    vis[i][j] = true;
               }
          }

     while (!s.empty())
     {
          vector<Node> black;
          while (!s.empty() && (*s.begin()).ct == 1)
          {
               Node tmp = *s.begin();
               s.erase(s.begin());
               black.push_back(tmp);
          }
          if (black.empty())
          {
               break;
          }

          for (auto &tmp : black)
          {
               for (int k = 0; k < 4; ++k)
               {
                    int nx = tmp.x + tx[k];
                    int ny = tmp.y + ty[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                         continue;
                    if (vis[nx][ny])
                         continue;
                    auto it = s.find({nx, ny, cnt[nx][ny]});
                    if (it != s.end())
                    {
                         Node newIt = *it;
                         s.erase(*it);
                         newIt.ct++;
                         if (newIt.ct == 1)
                              s.insert(newIt);
                    }
                    cnt[nx][ny]++;
               }
          }

          for (auto v : black)
               str[v.x][v.y] = '#';
     }

     int ans = 0;
     for (auto &v : str)
     {
          ans += count(all(v), '#');
     }
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