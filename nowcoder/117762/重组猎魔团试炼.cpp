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
     int n, q;
     cin >> n >> q;
     string s;
     cin >> s;
     vector<int> a(n);
     vector<bool> vis(n, 0);
     vector<int> ans;

     function<void(int p)> dfs = [&](int p)
     {
          if (p == n)
          {
               int tmp = 0;
               bool ok = 0;
               for (auto v : a)
               {
                    if (v != -1)
                    {
                         ok = 1;
                         tmp = tmp * 10 + v;
                    }
               }
               if (!ok)
                    return;
               if (tmp % q == 0)
               {
                    ans.push_back(tmp);
               }
               return;
          }

          a[p] = -1;
          dfs(p + 1);
          for (int i = 0; i < n; ++i)
          {
               if (vis[i])
                    continue;
               a[p] = s[i] - '0';
               vis[i] = 1;
               dfs(p + 1);
               vis[i] = 0;
               a[p] = -1;
          }
     };
     dfs(0);

     if (ans.empty())
          cout << -1;
     else
          cout << *min_element(all(ans));
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