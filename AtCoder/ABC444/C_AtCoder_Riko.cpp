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
     int n;
     cin >> n;
     vector<ll> a(n);
     cin >> a;
     sort(all(a));
     int maxN = count(all(a), a.back());
     vector<ll> ans;
     if ((a.size() - maxN) % 2 == 0)
     {
          int t = (a.size() - maxN) / 2;
          bool ok = true;
          for (int i = 0, r = 2 * t - 1; i < t; ++i, r--)
          {
               if (a[i] + a[r] != a.back())
               {
                    ok = false;
                    break;
               }
          }
          if (ok)
               ans.push_back(a.back());
     }
     if (a.size() % 2 == 0)
     {
          ll sum = 0;
          for (auto v : a)
               sum += v;
          ll L = sum / (a.size() / 2);
          multiset<int> s(all(a));
          bool ok = true;
          for (int i = 0; i < a.size() / 2; ++i)
          {
               int num = *s.begin();
               s.erase(s.begin());
               auto find = s.find(L - num);
               if (find == s.end())
               {
                    ok = false;
                    break;
               }
               s.erase(find);
          }
          if (ok)
               ans.push_back(L);
     }

     for (auto v : ans)
          cout << v << " ";
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