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
vector<int> sum(301);
void solve()
{
     ll l, r;
     cin >> l >> r;
     if(l >= 300){
          cout << "0\n";
          return;
     }
     r = min(r, 300ll);     
     cout << sum[r] - sum[l - 1] << endl;
}
int main()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     srand(time(nullptr));

     for (int i = 1; i <= 300; ++i)
     {
          string str = to_string(i * i);
          int tmp = 0;
          for (auto v : str)
          {
               tmp += v - '0';
          }
          if (tmp == i)
          {
               sum[i] = sum[i - 1] + 1;
          }
          else
          {
               sum[i] = sum[i - 1];
          }
     }

     int t = 1;
     cin >> t;
     while (t--)
     {
          solve();
     }
     return 0;
}