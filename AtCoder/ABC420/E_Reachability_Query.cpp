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
     vector<int> fa(n + 1, 0);
     for (int i = 0; i < n + 1; ++i)
          fa[i] = i;
     vector<pair<set<int>, set<int>>> g(n + 1);
     vector<bool> vis(n + 1, 0);
     for (int i = 1; i <= n; ++i)
          g[i].first.insert(i);
     function<int(int)> Find = [&](int p) -> int
     {
          if (fa[p] != p)
          {
               fa[p] = Find(fa[p]);
               // g[p].first.clear();
               // g[p].second.clear();
               // if (vis[p])
               //      g[fa[p]].second.insert(p);
               // else
               //      g[fa[p]].first.insert(p);
          }
          return fa[p];
     };
     while (m--)
     {
          int op, u, v;
          cin >> op;
          if (op == 1)
          {
               cin >> u >> v;
               int FA = Find(u);
               int FB = Find(v);
               if (FA != FB)
               {
                    int s1 = g[FA].first.size() + g[FA].second.size();
                    int s2 = g[FB].first.size() + g[FB].second.size();
                    if (s1 > s2)
                    {
                         swap(FA, FB);
                    }
                    fa[FA] = FB;
                    for (auto &v : g[FA].first)
                         g[FB].first.insert(v);
                    for (auto &v : g[FA].second)
                         g[FB].second.insert(v);
                    g[FA].first.clear();
                    g[FA].second.clear();
               }
          }
          else if (op == 2)
          {
               cin >> u;
               int FA = Find(u);
               if (vis[u])
               {
                    g[FA].first.insert(u);
                    g[FA].second.erase(u);
               }
               else
               {
                    g[FA].first.erase(u);
                    g[FA].second.insert(u);
               }
               vis[u] = !vis[u];
          }
          else
          {
               cin >> u;
               int FA = Find(u);
               if (g[FA].second.size() != 0)
                    cout << "Yes\n";
               else
                    cout << "No\n";
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
