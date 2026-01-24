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
     vector<ll> a(n + 1);
     for (int i = 0; i < m; ++i)
     {
          int x, y;
          cin >> x >> y;
          a[x]++;
          a[y]++;
     }
     for (int i = 1; i <= n; ++i)
     {
          ll sum = n - 1 - a[i];
          if (sum <= 2)
               cout << "0 ";
          else
          {
               ll ans = sum * (sum - 1) * (sum - 2);
               ans /= 6;
               cout << ans << " ";
          }
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