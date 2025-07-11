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
// void solve()
// {
//     int n = 0;
//     int k = 0;
//     int q = 0;
//     vector<int> A = make1("[1,2,3,1,2,3,1,2,3]");
//     vector<int> B = make1("");
//     vector<vector<int>> AA = make2("[[1,2],[2,5],[3,9],[1,15]]");
//     vector<vector<int>> BB = make2("");
//     Solution t;
//     // cout << t.beautifulSplits(A);
// }
struct cmp
{
     bool operator()(const pii &a, const pii &b) const
     {
          return a.second > b.second;
     }
};

void solve()
{
     int n;
     cin >> n;
     vector<vector<int>> g(n + 1, vector<int>());
     vector<int> dis(n + 1, 1e9), du(n + 1, 0);

     for (int i = 1, u, v; i <= n - 1; ++i)
     {
          cin >> u >> v;
          g[u].push_back(v);
          g[v].push_back(u);
          du[u]++, du[v]++;
     }

     priority_queue<pii, vector<pii>, cmp> Q;

     for (int i = 1; i <= n; ++i)
          if (du[i] == 1)
          {
               Q.push({i, 0});
               dis[i] = 0;
          }

     while (!Q.empty())
     {
          pii tmp = Q.top();
          Q.pop();
          if (tmp.second > dis[tmp.first])
               continue;

          for (auto &v : g[tmp.first])
          {
               if (tmp.second + 1 < dis[v])
               {
                    dis[v] = tmp.second + 1;
                    Q.push({v, dis[v]});
               }
          }
     }

     int Max = 0;
     set<int> S;
     for (int i = 1; i <= n; ++i)
     {
          if (dis[i] > Max)
          {
               Max = dis[i];
               S.clear();
               S.insert(i);
          }
          else if (dis[i] == Max)
          {
               S.insert(i);
          }
     }

     cout << S.size() << endl;
     for (auto v : S)
          cout << v << " ";
     cout << endl;
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
