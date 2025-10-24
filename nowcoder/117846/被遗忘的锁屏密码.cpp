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
     vector<int> a(6);
     int sum = 1e9;
     for (int i = 0; i < 1e6; ++i)
     {
          int tmp = i;
          for (int j = 0; j < 6; ++j)
          {
               a[j] = tmp % 10;
               tmp /= 10;
          }
          if (count(all(a), 0) >= 1)
               continue;

          int s = 0;
          for (int j = 0; j < 5; ++j)
          {
               s += gcd(a[j], a[j + 1]);
          }
          sum = min(sum, s);
     }
     for (int i = 0; i < 1e6; ++i)
     {
          int tmp = i;
          for (int j = 0; j < 6; ++j)
          {
               a[j] = tmp % 10;
               tmp /= 10;
          }
          if (count(all(a), 0) >= 1)
               continue;

          int Min = *min_element(all(a));
          int Max = *max_element(all(a));
          if (Min == Max)
               continue;
          auto tmpA = a;
          sort(all(tmpA));
          int twothMin = tmpA[upper_bound(all(tmpA), Min) - tmpA.begin()];
          if ((Min ^ twothMin) != Max)
               continue;
          int sgcd = a[0];
          int sxor = a[0];
          for (int j = 1; j < 6; ++j)
          {
               sgcd = gcd(sgcd, a[j]);
               sxor ^= a[j];
          }
          if (sgcd != Min)
               continue;
          if (sxor != twothMin)
               continue;

          int s = 0;
          for (int j = 0; j < 5; ++j)
          {
               s += gcd(a[j], a[j + 1]);
          }

          if (s != sum)
               continue;

          int LCM = a[0];
          for (int j = 1; j < 6; ++j)
          {
               LCM = lcm(LCM, a[j]);
          }

          vector<int> factors;
          for (int num = 1; num * num <= i; ++num)
          {
               if (i % num == 0)
               {
                    factors.push_back(num);
                    ll j = i / num;
                    if (j != num)
                         factors.push_back(j);
               }
          }
          if(factors.size()!=6)
               continue;
          cout << a;
          return;
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