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
ll POW(ll a, ll b)
{
     a %= MOD;
     if (b == 0)
          return 1;
     if (b % 2 == 0)
          return POW((a * a) % MOD, b / 2) % MOD;
     else
          return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}

void solve()
{
     ll n, m;
     cin >> n >> m;
     int x = 0;
     while (x * (x + 1) < 2 * n)
     {
          x++;
     }
     x = (x * (x + 1) / 2) == n ? x : x - 1;
     vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));  //>=1
     vector<vector<int>> dp0(n + 1, vector<int>(x + 1, 0)); //>=0
     for (int i = 1; i <= n; ++i)
     {
          for (int j = 1; j <= x; ++j)
          {
               if (j == 1)
               {
                    dp[i][j] = 1;
                    continue;
               }
               dp[i][j] = dp[i - 1][j - 1] + ((i - j >= 1) ? dp[i - j][j] : 0);
               dp[i][j] %= MOD;
          }
     }
     dp0[0] = vector<int>(x + 1, 1);
     for (int i = 1; i <= n; ++i)
     {
          for (int j = 1; j <= x; ++j)
          {
               dp0[i][j] = dp0[i][j - 1] + ((i - j >= 0) ? dp[i][j] : 0);
               dp0[i][j] %= MOD;
          }
     }
     ll ans = 0;
     for (int i = 1; i <= x; ++i)
     {
          ll tmp = (m % MOD * POW(m - 1, i - 1)) % MOD;
          ll Min = (1 + i) * i / 2;
          ans = (ans + (dp0[n - Min][i] * tmp) % MOD) % MOD;
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