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
     vector<vector<ll>> a(n, vector<ll>(m, 0));
     cin >> a;

     set<int> s;
     for (int i = 0; i < n; ++i)
     {
          set<int> ans;
          for (int j = 0; j < m; ++j)
          {
               if (s.find(a[i][j]) == s.end())
               {
                    ans.insert(a[i][j]);
                    s.insert(a[i][j]);
               }
          }
          for (auto v : ans)
               cout << v << " ";
          cout << endl;
     }
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