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
     int n, m, k;
     cin >> n >> m >> k;
     vector<vector<int>> g(n + 1);
     string str;
     cin >> str;
     str = '#' + str;
     for (int i = 0; i < m; i++)
     {
          int u, v;
          cin >> u >> v;
          g[u].push_back(v);
     }
     vector<vector<int>> dpA(n + 1, vector<int>(2 * k + 1, 0));
     vector<vector<int>> dpB(n + 1, vector<int>(2 * k + 1, 0));
     // B

     for (int j = 1; j <= n; ++j)
     {
          for (auto v : g[j])
          {
               if (str[v] == 'B')
               {
                    dpB[j][1] = 1;
                    break;
               }
          }
     }

     for (int j = 1; j <= n; ++j)
     {
          for (auto v : g[j])
          {
               if (dpB[v][1] == 0)
               {
                    dpA[j][2] = 1;
                    break;
               }
          }
     }

     for (int i = 3; i <= 2 * k; ++i)
     {
          // B
          if (i % 2 == 1)
          {
               for (int j = 1; j <= n; ++j)
               {
                    for (auto v : g[j])
                    {
                         if (dpA[v][i - 1] == 0)
                         {
                              dpB[j][i] = 1;
                              break;
                         }
                    }
               }
          }
          else // A
          {
               for (int j = 1; j <= n; ++j)
               {
                    for (auto v : g[j])
                    {
                         if (dpB[v][i - 1] == 0)
                         {
                              dpA[j][i] = 1;
                              break;
                         }
                    }
               }
          }
     }

     cout << (dpA[1][2*k] ? "Alice\n" : "Bob\n");
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