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
     int n, q;
     cin >> n >> q;
     string tw;
     cin >> tw;
     vector<int> w(n + 1);
     vector<vector<int>> up(n + 1);
     vector<vector<int>> down(n + 1);
     for (int i = 0; i < n; ++i)
          w[i + 1] = tw[i] - '0';
     vector<vector<int>> g(n + 1);
     for (int i = 1, u, v; i < n; ++i)
     {
          cin >> u >> v;
          g[v].push_back(u);
          g[u].push_back(v);
     }

     function<void(int, int)> dfsup = [&](int p, int fa)
     {
          up[p].push_back(w[p]);
          for (int i = 0; i < up[fa].size() && i < 20; ++i)
          {
               up[p].push_back(up[fa][i] + (w[p] << (i + 1)));
          }
          for (auto &v : g[p])
          {
               if (v == fa)
                    continue;
               dfsup(v, p);
          }
     };
     function<void(int, int)> dfsdown = [&](int p, int fa)
     {
          down[p].push_back(w[p]);
          for (int i = 0; i < down[fa].size() && i < 20; ++i)
          {
               down[p].push_back((down[fa][i] << 1) + w[p]);
          }
          for (auto &v : g[p])
          {
               if (v == fa)
                    continue;
               dfsdown(v, p);
          }
     };

     dfsdown(1, 0);
     dfsup(1, 0);

     vector<bool> vis((1 << 22), 0);
     for (auto &v : up)
     {
          for (auto &vv : v)
               vis[vv] = true;
     }
     for (auto &v : down)
     {
          for (auto &vv : v)
               vis[vv] = true;
     }

     int x;
     while (q--)
     {
          cin >> x;
          cout << (vis[x] ? "YES\n" : "NO\n");
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
