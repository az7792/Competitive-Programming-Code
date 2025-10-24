#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
//ll MOD = 1e9 + 7;
ll MOD = 998224353;

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
ll sum[1000000 + 100]{};
void solve()
{
     int l, r;
     cin >> l >> r;
     l %= 251024;
     r %= 251024;
     if (l > r)
     {
          cout << 0 << endl;
          return;
     }
     cout << (sum[r] - sum[l - 1] + MOD) % MOD << endl;
}
int main()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     srand(time(nullptr));
     for (ll i = 1; i <= 1000000; ++i)
     {
          sum[i] = sum[i - 1] + i * i;
          sum[i] %= MOD;
     }
     int t = 1;
     cin >> t;
     while (t--)
     {
          solve();
     }
     return 0;
}