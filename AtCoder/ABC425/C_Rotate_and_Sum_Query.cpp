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
     vector<ll> a(n + 1);
     vector<ll> sum(n + 1, 0);
     for (int i = 1; i <= n; ++i)
     {
          cin >> a[i];
          sum[i] = sum[i - 1] + a[i];
     }
     int L = 1;
     while (q--)
     {
          int op, x, y;
          cin >> op;
          if (op == 1)
          {
               cin >> x;
               L = ((L - 1) - x + n) % n + 1;
          }
          else
          {
               cin >> x >> y;
               //....L....
               if (y < L)
               {
                    //.x..L....
                    x = n - (L - x - 1);
                    y = n - (L - y - 1);
                    cout << sum[y] - sum[x - 1] << endl;
               }
               else if (x > L)
               {
                    x = x - L + 1;
                    y = y - L + 1;
                    cout << sum[y] - sum[x - 1] << endl;
               }
               else
               {
                    //..x.L.y..
                    y = y - L + 1;
                    ll s1 = sum[y];
                    x = n - (L - x - 1);
                    ll s2 = sum[n] - sum[x - 1];
                    cout << s1 + s2 << endl;
               }
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