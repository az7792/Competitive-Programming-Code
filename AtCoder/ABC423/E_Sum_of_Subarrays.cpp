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
     vector<ll> a(n + 1), sum(n + 2, 0), sum1(n + 2, 0), sum2(n + 2, 0), sumtmp(n + 2, 0);
     for (int i = 1; i <= n; ++i)
     {
          cin >> a[i];
     }
     for (int i = n; i >= 1; --i)
     {
          sum[i] = sum[i + 1] + a[i];
          sum1[i] = sum1[i + 1] + sum[i];
          sumtmp[i] = sumtmp[i + 1] + (n - i + 1) * a[i];
          sum2[i] = sum2[i + 1] + sumtmp[i];
     }

     while (q--)
     {
          ll l, r;
          cin >> l >> r;
          ll s1 = sum2[l] - sum2[r + 1] - (r - l + 1) * sumtmp[r + 1];
          ll s2 = sum1[l] - sum1[r + 1] - (r - l + 1) * sum[r + 1];
          s1 -= s2 * (n - r);
          cout << s1 << endl;
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