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
void solve()
{
     int n, m;
     cin >> n >> m;
     vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
     for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= m; ++j)
               cin >> a[i][j];
     map<int, vector<int>> mp;
     int ct = 0;
     for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= m; ++j)
               if (a[i][j] != min(i, j))
                    mp[min(i, j)].push_back(a[i][j]), ct++;
     if (ct <= 1)
     {
          cout << n * m - ct;
          return;
     }
     for (auto &v : mp)
          sort(all(v.second));
     for (auto &v : mp)
     {
          for (auto &vv : v.second)
          {
               if (mp.find(vv) == mp.end())
                    continue;
               auto &tmp = mp[vv];
               int p = lower_bound(all(tmp), v.first) - tmp.begin();
               if (p != tmp.size() && tmp[p] == v.first)
               {
                    cout << n * m - (ct - 2);
                    return;
               }
          }
     }
     for (auto &v : mp)
     {
          for (auto &vv : v.second)
          {
               if (mp.find(vv) != mp.end())
               {
                    cout << n * m - (ct - 1);
                    return;
               }
          }
     }
     cout << n * m - (ct - 0);
     return;
     // for (int i = 1; i <= n; ++i)
     //      for (int j = 1; j <= m; ++j)
     //           a[i][j] = min(i, j);
     // for (int i = 1; i <= n; ++i)
     //      for (int j = 1; j <= m; ++j)
     //           cout << a[i][j] << " \n"[j == m];
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
