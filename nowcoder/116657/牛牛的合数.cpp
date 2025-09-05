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
struct Math
{
     ll mod;
     vector<bool> nisp; // false 是质数
     vector<int> isp;

     Math(ll MMod)
     {
          mod = MMod;
     }

     ll gcd(ll a, ll b)
     {
          while (b != 0)
          {
               ll temp = b;
               b = a % b;
               a = temp;
          }
          return a;
     }
     ll exgcd(ll a, ll b, ll &x, ll &y)
     {
          if (b == 0)
          {
               x = 1, y = 0;
               return a;
          }
          ll res = exgcd(b, a % b, x, y);
          ll t = x;
          x = y;
          y = t - (a / b) * y;
          return res;
     }

     ll lcm(ll a, ll b)
     {
          return (a * b) / gcd(a, b);
     }

     ll POW(ll a, ll b)
     {
          a %= mod;
          if (b == 0)
               return 1;
          if (b % 2 == 0)
               return POW((a * a) % mod, b / 2) % mod;
          else
               return (POW((a * a) % mod, b / 2) % mod * a) % mod;
     }

     void initOula(int n) // 1-n的素数
     {
          nisp.resize(n + 1, 0);
          nisp[0] = nisp[1] = 1;
          for (int i = 2; i <= n; ++i)
          {
               if (!nisp[i])
                    isp.push_back(i);
               for (int j = 0; j < isp.size() && isp[j] * i <= n; ++j)
               {
                    nisp[isp[j] * i] = true;
                    if (i % isp[j] == 0)
                         break;
               }
          }
     }

     bool isPrime(int x)
     {
          if (x <= 1)
               return 0;
          for (int i = 2; i <= x / i; ++i)
               if (x % i == 0)
                    return 0;
          return 1;
     }
};
Math math(MOD);
void solve()
{
     int x;
     cin >> x;
     for (int i = 1; i < x; ++i)
     {
          if ((x ^ i) == 1)
               continue;
          if (math.nisp[x ^ i])
          {
               cout << i << endl;
               return;
          }
     }
     cout << "-1\n";
}
int main()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     srand(time(nullptr));
     math.initOula(1e6);
     int t = 1;
     cin >> t;
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
