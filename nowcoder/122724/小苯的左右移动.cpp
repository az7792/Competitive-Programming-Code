#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
ll MOD = 998244353;

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
     ll n;
     ull k;
     cin >> n >> k;
     vector<ll> a(n);
     cin >> a;

     ll R = 0;

     bitset<64> bt(k);

     // int len = 0;

     // for (int i = 63; i >= 0; --i)
     // {
     //      if (bt[i] == 1)
     //      {
     //           len = i + 1;
     //           break;
     //      }
     // }

     for (int i = 1; i <= n; ++i)
     {
          if (i % 2 == 0)
          {
               R += a[i - 1];
          }
          else
          {
               R -= a[i - 1];
          }

          if (R > 0)
          {
               bt >>= R;
               R = 0;
          }
     }

     ll L = -R;

     ll ans = 0;

     for (int i = 0; i < 63; ++i)
     {
          if (bt[i] == 1)
          {
               ans += POW(2, i + L);
               ans %= MOD;
          }
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