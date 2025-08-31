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
     ll n, a, k;
     cin >> n >> a >> k;
     if (n == 1)
     {
          if (a == k)
          {
               cout << a;
          }
          else
          {
               cout << "-1";
          }
          return;
     }
     // 2 * x + y = a
     // x + y = k
     // 2(k - y) + y = a
     // 2k - y == a
     // y = 2k - a
     // x = a - k
     ll x = a - k;
     ll y = 2 * k - a;
     if (x < 0 || y < 0)
     {
          cout << "-1";
          return;
     }
     if (2 * x <= n)
     {
          if (2 * x + y < n)
          {
               cout << "-1";
               return;
          }
          vector<int> a(2 * x);
          for (int i = 0; i < x; ++i)
               a[2 * i] = a[2 * i + 1] = 1;
          for (int i = 0; i < n - 2 * x; ++i)
               a.push_back(1);
          a[0] += y - (n - 2 * x);
          cout << a;
     }
     else
     {
          if (n % 2 == 0)
          {
               vector<int> a(n, 1);
               x -= n / 2;
               a[0] += y;
               a[0] += x;
               a[1] += x;
               cout << a;
          }
          else
          {
               vector<int> a(n, 1);
               x -= n / 2;
               a[n - 1] = 0;
               if (y >= 1)
               {
                    a[n - 1] = 1;
                    y--;
                    a[0] += y;
                    a[0] += x;
                    a[1] += x;
                    cout << a;
               }
               else
               {
                    cout << "-1";
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
