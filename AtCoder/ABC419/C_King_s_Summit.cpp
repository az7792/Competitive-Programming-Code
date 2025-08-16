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
     ll x0, y0, x1, y1;
};
void solve()
{
     ll n;
     cin >> n;
     vector<pair<ll, ll>> g(n);
     vector<Node> tmp(n);
     for (int i = 0; i < n; ++i)
          cin >> g[i].first >> g[i].second;
     ll l = 0, r = 2e9 + 1e3, mid;
     function<bool()> ok = [&]() -> bool
     {
         // cout << 1;
          Node Min = tmp[0];
          for (int i = 1; i < n; ++i)
          {
               ll x0 = max(tmp[i].x0, Min.x0);
               ll y0 = max(tmp[i].y0, Min.y0);
               ll x1 = min(tmp[i].x1, Min.x1);
               ll y1 = min(tmp[i].y1, Min.y1);
               if (x0 > x1 || y0 > y1)
                    return false;
               Min = {x0, y0, x1, y1};
          }
          return true;
     };
     while (l < r)
     {
          mid = (l + r) >> 1;
          for (int i = 0; i < n; ++i)
          {
               tmp[i].x0 = g[i].first - mid;
               tmp[i].y0 = g[i].second - mid;
               tmp[i].x1 = g[i].first + mid;
               tmp[i].y1 = g[i].second + mid;
          }
          if (ok())
               r = mid;
          else
               l = mid + 1;
     }
     cout << l;
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
