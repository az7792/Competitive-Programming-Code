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
     int n, m, q;
     cin >> n >> m >> q;
     vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
     vector<int> ti(n + 1, 1e9);
     int ct = 0;
     while (q--)
     {
          int a, b;
          cin >> a >> b;
          ct++;
          vis[a][b] = 1;
          bool ok = true;
          for (int i = 1; i <= m; ++i)
               if (vis[a][i] == 0)
               {
                    ok = false;
                    break;
               }
          if (ok)
          {
               ti[a] = ct;
          }
     }
     vector<pii> tmp;
     for (int i = 1; i <= n; ++i)
     {
          if (ti[i] != 1e9)
          {
               tmp.push_back({ti[i], i});
          }
     }
     sort(all(tmp));
     for (auto v : tmp)
          cout << v.second << " ";
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