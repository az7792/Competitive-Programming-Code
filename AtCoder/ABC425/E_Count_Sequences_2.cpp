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

struct combN
{
     ll mod;
     vector<vector<ll>> C;

     combN(int n, ll m) : mod(m)
     {
          C.assign(n + 1, vector<ll>(n + 1, 0));
          for (int i = 0; i <= n; i++)
          {
               C[i][0] = C[i][i] = 1 % mod;
               for (int j = 1; j < i; j++)
               {
                    C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
               }
          }
     }

     ll get(int n, int m)
     {
          if (m < 0 || m > n)
               return 0;
          return C[n][m];
     }
};
combN *com = nullptr;

void solve()
{
     int n;
     cin >> n;
     vector<int> a(n + 1, 0);
     int sum = 0;
     for (int i = 1; i <= n; ++i)
     {
          cin >> a[i];
          sum += a[i];
     }
     vector<ll> dp(n + 1, 0);
     dp[1] = com->get(sum, a[1]);
     sum -= a[1];
     for (int i = 2; i <= n; ++i)
     {
          dp[i] = (dp[i - 1] * com->get(sum, a[i])) % MOD;
          sum -= a[i];
     }
     cout << dp[n] << endl;
}
int main()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     srand(time(nullptr));
     int t = 1;
     cin >> t >> MOD;
     com = new combN(6000, MOD);
     while (t--)
     {
          solve();
     }
     return 0;
}