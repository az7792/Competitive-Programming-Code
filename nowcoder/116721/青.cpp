#include <bits/stdc++.h>
using namespace std;
vector<int> make1(string strArr);
vector<vector<int>> make2(string strArr);
#define endl '\n'
// leetcode--------start
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

class Solution
{
public:
     int beautifulSplits(vector<int> &nums)
     {
          return 1;
     }
};
// leetcode--------end
void solve()
{
     ll n, m;
     cin >> n >> m;
     vector<ll> a(n);
     cin >> a;
     sort(all(a));
     for (int i = 0; i < n - 1; ++i)
     {
          if (a[i + 1] - a[i] - 1 >= 2)
          {
               cout << a[i + 1] << " " << a[i] << " " << a[i] + 1 << " " << a[i + 1] - 1;
               return;
          }
     }
     vector<int> b;
     if (a.front() != 1)
          b.push_back(a.front() - 1);
     if (a.back() != n + m)
          b.push_back(a.back() + 1);
     for (int i = 0; i < n - 1; ++i)
     {
          if (a[i + 1] - a[i] - 1 == 1)
          {
               b.push_back(a[i] + 1);
          }
     }
     sort(all(b));
     for (int i = 0; i < b.size(); ++i)
     {
          if (i - 1 >= 0 && b[i] - b[i - 1] - 1 >= 2)
          {
               cout << b[i - 1] + 1 << " " << b[i] - 1 << " " << b[i] << " " << b[i - 1];
               return;
          }
          if (i + 1 < b.size() && b[i + 1] - b[i] - 1 >= 2)
          {
               cout << b[i + 1] - 1 << " " << b[i] + 1 << " " << b[i] << " " << b[i + 1];
               return;
          }
     }
     if (b.size() <= 1)
     {
          cout << -1;
          return;
     }
     if (b.back() - b.front() - 1 >= 3)
     {
          cout << b.front() + 1 << " " << b.back() - 1 << " " << b.front() << " " << b.back();
          return;
     }
     cout << -1;
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

vector<int> make1(string strArr)
{
     vector<int> result;
     if (strArr.empty())
          return result;
     string item;
     strArr = strArr.substr(1, strArr.size() - 2);
     stringstream stream(strArr);
     while (getline(stream, item, ','))
     {
          result.push_back(stoi(item));
     }
     return result;
}
vector<vector<int>> make2(string strArr)
{
     vector<vector<int>> result;
     if (strArr.empty())
          return result;
     string item;
     strArr = strArr.substr(2, strArr.size() - 4);
     stringstream stream(strArr);
     bool first = true;
     while (getline(stream, item, ']'))
     {
          if (!item.empty())
          {
               if (!first)
                    item = item.substr(2);
               vector<int> innerResult = make1("[" + item + "]");
               result.push_back(innerResult);
               first = false;
          }
     }
     return result;
}
