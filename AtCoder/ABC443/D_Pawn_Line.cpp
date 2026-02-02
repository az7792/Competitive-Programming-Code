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

vector<int> a;
set<pii> s;
ll ans = 0;

int n;
int hit;
void func(int p)
{
     int L = p;
     while (1)
     {
          if (L <= 0)
               break;
          if (abs(a[L - 1] - a[L]) <= 1)
          {
               break;
          }
          if (a[L - 1] < a[L])
               break;
          ll add = a[L - 1] - a[L] - 1;
          ans += add;
          s.erase({a[L - 1], L - 1});
          a[L - 1] -= add;
          hit = 1;
          s.insert({a[L - 1], L - 1});
     }
     int R = p;
     while (1)
     {
          if (R >= n - 1)
               break;
          if (abs(a[R + 1] - a[R]) <= 1)
          {
               break;
          }
          if (a[R + 1] < a[R])
               break;
          ll add = a[R + 1] - a[R] - 1;
          ans += add;
          s.erase({a[R + 1], R + 1});
          a[R + 1] -= add;
          hit = 1;
          s.insert({a[R + 1], R + 1});
     }
};

bool ok(int p)
{
     if (p - 1 >= 0 && abs(a[p - 1] - a[p]) > 1)
          return false;
     if (p + 1 <= n - 1 && abs(a[p + 1] - a[p]) > 1)
          return false;
     return 1;
};

void solve()
{
     // n-1 - n+1
     cin >> n;
     a.resize(n);
     s.clear();
     cin >> a;
     ans = 0;

     for (int i = 0; i < n; ++i)
     {
          s.insert({a[i], i});
     }

     while (1)
     {
          hit = 0;
          for (auto &v : s)
          {
               if (!ok(v.second))
                    func(v.second);
          }
          if(hit == 0)
               break;
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