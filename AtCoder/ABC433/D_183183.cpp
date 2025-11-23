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
     ll n, m;
     cin >> n >> m;
     vector<ll> a(n);
     cin >> a;
     vector<ll> tmp(11);
     tmp[0] = 1;
     for (int i = 1; i <= 10; ++i)
     {
          tmp[i] = tmp[i - 1] * 10;
     }

     vector<map<int, int>> dp1(11);
     vector<ll> dp2(n);

     for (int i = 0; i < n; ++i)
     {
          dp2[i] = a[i] % m;
          for (int j = 0; j <= 10; ++j)
          {
               ll tt = (a[i] % m * tmp[j] % m) % m;
               dp1[j][tt]++;
          }
     }

     ll ans = 0;

     auto get = [&](ll num) -> int
     {
          int ct = 0;
          while (num != 0)
          {
               ct++;
               num /= 10;
          }
          return ct;
     };

     for (int i = 0; i < n; ++i)
     {
          ll v = dp2[i];
          if (v == 0)
          {
               int cc = get(a[i]);
               ans += dp1[cc][0];
          }
          else
          {
               int cc = get(a[i]);
               ans += dp1[cc][m - v];
          }
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