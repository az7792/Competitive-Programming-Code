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
     ll n, x, y;
     cin >> n >> x >> y;
     vector<ll> a(n + 1);
     for (int i = 1; i <= n; ++i)
          cin >> a[i];

     vector<ll> diff(n + 1);
     vector<ll> L(n + 1), R(n + 1);
     L[1] = 0;
     R[1] = a[1];

     ll sum = 0, tmpS = 0;
     ll l = 0, r = a[1];
     for (int i = 2; i <= n; ++i)
     {
          ll t1 = (a[i] - a[i - 1]) * x;
          if (t1 % (x - y) != 0)
          {
               cout << -1;
               return;
          }
          diff[i] = t1 / (x - y);
          tmpS += diff[i];
          sum += tmpS;
          if (abs(tmpS) > 1e9)
          {
               cout << -1;
               return;
          }
          L[i] = max(0ll, -tmpS);
          R[i] = min(a[i], a[i] - tmpS);
          l = max(l, L[i]);
          r = min(r, R[i]);
     }

     if (l > r)
     {
          cout << -1;
          return;
     }

     cout << r * n + sum;
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