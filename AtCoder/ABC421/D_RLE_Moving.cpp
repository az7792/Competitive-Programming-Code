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
struct Node
{
     ll x, y;
     bool operator==(const Node &a) const
     {
          return (x == a.x && y == a.y);
     }
};
map<char, pair<ll, ll>> mp = {{'R', {0, 1}}, {'L', {0, -1}}, {'D', {1, 0}}, {'U', {-1, 0}}};
void solve()
{
     Node p1, p2;
     cin >> p1.x >> p1.y >> p2.x >> p2.y;
     ll n, m, l;
     cin >> n >> m >> l;
     vector<pair<char, ll>> a1(m), a2(l);
     for (int i = 0; i < m; ++i)
          cin >> a1[i].first >> a1[i].second;
     for (int i = 0; i < l; ++i)
          cin >> a2[i].first >> a2[i].second;

     ll c1 = 0, c2 = 0;
     ll ans = 0;
     while (true)
     {
          if (c1 >= m && c2 >= l)
               break;
          char &ch1 = a1[c1].first;
          char &ch2 = a2[c2].first;
          ll st = min(a1[c1].second, a2[c2].second);

          a1[c1].second -= st;
          a2[c2].second -= st;
          if (a1[c1].second == 0)
               c1++;
          if (a2[c2].second == 0)
               c2++;

          if (p1 == p2)
          {
               if (ch1 == ch2)
                    ans += st;
          }
          else if (p1.x == p2.x)
          {
               if (abs(p1.y - p2.y) % 2 == 0)
               {
                    if (p1.y < p2.y)
                    {
                         if (ch1 == 'R' && ch2 == 'L')
                         {
                              if ((p1.y + p2.y) / 2 - p1.y <= st)
                                   ans++;
                         }
                    }
                    else
                    {
                         if (ch1 == 'L' && ch2 == 'R')
                         {
                              if ((p1.y + p2.y) / 2 - p2.y <= st)
                                   ans++;
                         }
                    }
               }
          }
          else if (p1.y == p2.y)
          {
               if (abs(p1.x - p2.x) % 2 == 0)
               {
                    if (p1.x < p2.x)
                    {
                         if (ch1 == 'D' && ch2 == 'U')
                         {
                              if ((p1.x + p2.x) / 2 - p1.x <= st)
                                   ans++;
                         }
                    }
                    else
                    {
                         if (ch1 == 'U' && ch2 == 'D')
                         {
                              if ((p1.x + p2.x) / 2 - p2.x <= st)
                                   ans++;
                         }
                    }
               }
          }
          else if (abs(p1.x - p2.x) == abs(p1.y - p2.y) && abs(p1.x - p2.x) <= st)
          {
               ll tmpSt = abs(p1.x - p2.x);
               if (Node{p1.x + mp[ch1].first * tmpSt, p1.y + mp[ch1].second * tmpSt} == Node{p2.x + mp[ch2].first * tmpSt, p2.y + mp[ch2].second * tmpSt})
               {
                    ans++;
               }
          }
          p1.x += mp[ch1].first * st;
          p1.y += mp[ch1].second * st;
          p2.x += mp[ch2].first * st;
          p2.y += mp[ch2].second * st;
     }
     cout << ans;
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
