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
     int n;
     cin >> n;
     vector<int> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];
     vector<int> ql, qr;
     int l = 0, r = n - 1;
     map<int, int> mp;
     while (l <= r)
     {
          if (a[l] != a[r])
          {
               ql.push_back(a[l]);
               mp[a[l]]++;
               qr.push_back(a[r]);
               mp[a[r]]++;
          }
          l++, r--;
     }

     if (mp.size() == 0)
     {
          cout << "0\n";
          return;
     }

     map<int, vector<int>> pos;
     for (int i = 0; i < ql.size(); ++i)
     {
          pos[ql[i]].push_back(i);
          pos[qr[i]].push_back(i);
     }

     int Max1 = -1000;
     for (auto v : mp)
          Max1 = max(Max1, v.second);
     vector<pii> q;
     for (auto v : mp)
     {
          q.push_back(v);
     }
     int ans = 1e9;
     for (int i = 0; i < q.size(); ++i)
     {
          for (auto v : pos[q[i].first])
          {
               mp[ql[v]]--;
               mp[qr[v]]--;
          }
          int tMax = -1000;
          int pn = -1;
          for (auto v : mp)
          {
               if (v.second == 0)
                    continue;
               if (tMax < v.second)
               {
                    tMax = v.second;
                    pn = v.first;
               }
          }
          if (tMax == -1000)
          {
               cout << pos[q[i].first].size() << endl;
               return;
          }

          int offset = 0;
          for (auto v : pos[q[i].first])
          {
               if (ql[v] == pn)
                    offset++;
               if (qr[v] == pn)
                    offset++;
          }
          int a1 = pos[q[i].first].size();
          int a2 = pos[pn].size() - offset;
          int a3 = ql.size() - a1 - a2;
          ans = min(ans, a1 + a2 + 2 * a3);

          for (auto v : pos[q[i].first])
          {
               mp[ql[v]]++;
               mp[qr[v]]++;
          }
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
