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
     vector<vector<int>> g(n + 1);
     vector<int> num(n + 1, 0);
     vector<vector<int>> FA(n + 1, vector<int>(30));
     vector<int> dep(n + 1, 0);
     num[0] = -1;
     for (int i = 1, u, v; i < n; ++i)
     {
          cin >> u >> v;
          g[v].push_back(u);
          g[u].push_back(v);
     }
     function<void(int, int)> dfs1 = [&](int p, int fa)
     {
          FA[p][0] = fa;
          num[p] = num[fa] + 1;
          dep[p] = dep[fa] + 1;
          for (auto &v : g[p])
          {
               if (v == fa)
                    continue;
               dfs1(v, p);
          }
     };
     function<int(int, int)> LCA = [&](int x, int y) -> int
     {
          if (dep[x] < dep[y])
               swap(x, y);
          while (dep[x] > dep[y])
          {
               x = FA[x][(int)log2(dep[x] - dep[y])];
          }
          if (x == y)
               return x;
          for (int j = 29; j >= 0; --j)
               if (FA[x][j] != FA[y][j])
                    x = FA[x][j], y = FA[y][j];
          return FA[x][0];
     };
     dfs1(n, 0);
     for (int j = 1; j < 30; ++j)
          for (int i = 1; i <= n; ++i)
               FA[i][j] = FA[FA[i][j - 1]][j - 1];
     int node = 1;
     ll ans = 0;
     for (int i = 1; i <= n; ++i)
     {
          node = LCA(node, i);
          ans += num[node] + 1;
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
