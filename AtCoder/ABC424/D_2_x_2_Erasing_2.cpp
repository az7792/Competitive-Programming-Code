#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 1, 0, 1};
int ty[] = {0, 1, 1, 0};
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
     vector<string> g(n);
     for (int i = 0; i < n; ++i)
          cin >> g[i];
     vector<uint8_t> bit(n, 0);
     for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
               if (g[i][j] == '#')
                    bit[i] |= (1 << j);
     vector<vector<int>> dp(n, vector<int>((1 << m), 1e9));
     auto isok = [&](uint8_t a, uint8_t b) -> bool { // a是b的超集
          return ((a & b) == b);
     };
     auto get = [](uint8_t a, int p) -> int
     {
          return ((a >> p) & 1);
     };
     for (int i = 0; i < (1 << m); ++i)
     {
          if (!isok(bit[0], i))
               continue;
          int ct = 0;
          for (int j = 0; j < m; ++j)
          {
               if (get(bit[0], j) == 1 && get(i, j) == 0)
                    ct++;
          }
          dp[0][i] = ct;
     }
     for (int i = 1; i < n; ++i)
     {
          for (int j = 0; j < (1 << m); ++j) // i
          {
               for (int k = 0; k < (1 << m); ++k) // i-1
               {
                    if (dp[i - 1][k] == 1e9)
                         continue;
                    if (!isok(bit[i], j))
                         continue;
                    bool ok = true;
                    for (int g = 1; g < m; ++g)
                    {
                         if (get(j, g) == 1 && get(j, g - 1) == 1 && get(k, g) == 1 && get(k, g - 1) == 1)
                         {
                              ok = false;
                              break;
                         }
                    }
                    if (!ok)
                         continue;
                    int ct = 0;
                    for (int g = 0; g < m; ++g)
                    {
                         if (((bit[i] >> g) & 1) == 1 && ((j >> g) & 1) == 0)
                              ct++;
                    }
                    dp[i][j] = min(dp[i][j], ct + dp[i - 1][k]);
               }
          }
     }
     int ans = 1e9;
     for (int i = 0; i < (1 << m); ++i)
     {
          if (!isok(bit[n-1], i))
               continue;
          ans = min(ans, dp[n - 1][i]);
     }
     cout << ans << endl;
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