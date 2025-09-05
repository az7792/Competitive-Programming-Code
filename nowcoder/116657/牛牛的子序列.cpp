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
     int n, m;
     cin >> n >> m;
     vector<int> a(n), b(m);
     cin >> a >> b;
     if (n > m)
     {
          cout << "-1\n";
          return;
     }
     map<int, int> na, nb;
     for (auto v : a)
          na[v]++;
     for (auto v : b)
          nb[v]++;
     if (na.size() != nb.size())
     {
          cout << "-1\n";
          return;
     }
     for (auto v : na)
     {
          if (v.second > nb[v.first])
          {
               cout << "-1\n";
               return;
          }
     }

     vector<pii> qb;
     vector<pii> qa;
     for (auto v : b)
     {
          if (qb.empty())
               qb.push_back({v, 1});
          else if (qb.back().first == v)
               qb.back().second++;
          else
               qb.push_back({v, 1});
     }
     for (auto v : a)
     {
          if (qa.empty())
               qa.push_back({v, 1});
          else if (qa.back().first == v)
               qa.back().second++;
          else
               qa.push_back({v, 1});
     }
     if (qb.size() != qa.size())
     {
          cout << "-1\n";
          return;
     }
     for (int i = 0; i < qa.size(); ++i)
     {
          if (qa[i].first != qb[i].first)
          {
               cout << "-1\n";
               return;
          }
          if (qa[i].second > qb[i].second)
          {
               cout << "-1\n";
               return;
          }
     }
     int ans = -1;
     for (int i = 0; i < qb.size(); ++i)
     {
          int Min = 0;
          for (int j = 0; j <= 18; ++j)
          {
               if (qa[i].second * (1 << j) >= qb[i].second)
               {
                    Min = j;
                    break;
               }
          }

          ans = max(ans, Min);
     }
     cout << ans << endl;
     return;
     for (int i = 0; i < 18; ++i)
     {
          bool ok = true;
          for (int j = 0; j < qb.size(); ++j)
          {
               auto v = qb[j];
               // 1 -> 2^i
               // 2 -> 2 * 2^(i)
               // t -> t * 2^(i)
               int minNum;
               for (int t = 1;; ++t)
               {
                    if (t * (1 << i) >= v.second)
                    {
                         minNum = t;
                         break;
                    }
               }
               if (minNum > qa[j].second)
               {
                    ok = false;
                    break;
               }
          }

          if (ok)
          {
               cout << i << endl;
               return;
          }
     }
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
