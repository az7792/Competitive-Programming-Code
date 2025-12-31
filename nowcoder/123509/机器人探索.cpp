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

bool eq(char c1, char c2)
{
     if (c1 == 'L' && c2 == 'R')
          return true;
     if (c1 == 'R' && c2 == 'L')
          return true;
     if (c1 == 'U' && c2 == 'D')
          return true;
     if (c1 == 'D' && c2 == 'U')
          return true;
     return false;
}

void solve()
{
     int n;
     cin >> n;
     string str;
     cin >> str;

     map<char, int> mp;
     for (auto v : str)
          mp[v]++;

     if (mp.size() == 1)
     {
          cout << 1 + (*mp.begin()).second;
     }
     else if (mp.size() == 2)
     {
          char c1 = (*mp.begin()).first;
          char c2 = (*mp.rbegin()).first;
          if (eq(c1, c2))
          {
               cout << 1 + max(mp[c1], mp[c2]);
          }
          else
          {
               cout << 1 + mp[c1] + mp[c2];
          }
     }
     else if (mp.size() == 3)
     {
          ll sum = 0;
          for (auto v : mp)
               sum += v.second;
          cout << 1 + sum;
     }
     else
     {
          ll sum = 0;
          for (auto v : mp)
               sum += v.second;

          if (mp['R'] == mp['L'] && mp['U'] == mp['D'])
          {
               cout << sum;
          }
          else
               cout << sum + 1;
     }
     cout << endl;
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