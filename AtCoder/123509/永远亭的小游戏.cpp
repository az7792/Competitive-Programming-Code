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
     int n, m, k;
     cin >> n >> m >> k;
     vector<ll> a(n), b(m), c(k);
     cin >> a >> b >> c;
     ll s1 = 0;
     for (auto v : a)
     {
          s1 += v;
          s1 %= MOD;
     }
     s1 = s1 * POW(n, MOD - 2);
     s1 %= MOD;
     ll s2 = 0;
     for (auto v : b)
     {
          s2 += s1 * v;
          s2 %= MOD;
     }
     s2 = s2 * POW(m, MOD - 2);
     s2 %= MOD;
     ll s3 = 0;
     for (auto v : c)
     {
          s3 += s2 * v;
          s3 %= MOD;
     }
     s3 = s3 * POW(k, MOD - 2);
     s3 %= MOD;
     cout << s3;
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