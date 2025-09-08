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
// ll MOD = 1e9 + 7;
ll MOD = 998244353;

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
ll POW(ll a, ll b)
{
     a %= MOD;
     if (b == 0)
          return 1;
     if (b % 2 == 0)
          return POW((a * a) % MOD, b / 2) % MOD;
     else
          return (POW((a * a) % MOD, b / 2) % MOD * a) % MOD;
}
vector<bool> ok(20001, 0);
vector<int> W;
bool isW(int num)
{
     int tmp = sqrt(num);
     return tmp * tmp == num;
}
void init()
{
     int s = 0;
     for (int i = 1; i <= 20000; ++i)
     {
          if (!isW(i))
               continue;
          s = 0;
          string tmp = to_string(i);
          for (auto v : tmp)
               s += v - '0';
          if (isW(s))
               ok[i] = true, W.push_back(i);
     }
}
vector<vector<bool>> dp(101, vector<bool>(20001, 0));
void init2()
{
     dp[0][0] = 1;
     for (int i = 1; i <= 100; i++)
     {
          for (int j = 0; j <= 20000; j++)
          {
               for (int v : W)
               {
                    if (j >= v && dp[i - 1][j - v])
                    {
                         dp[i][j] = true;
                    }
               }
          }
     }
}
void solve()
{
     int n;
     cin >> n;
     vector<ll> a(n + 1);
     int sum = 0;
     for (int i = 1; i <= n; ++i)
     {
          cin >> a[i];
          sum += a[i];
     }
     if (dp[n][sum])
          cout << n << endl;
     else
          cout << n - 1 << endl;
}
int main()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     srand(time(nullptr));
     int t = 1;
     cin >> t;
     init();
     init2();
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
