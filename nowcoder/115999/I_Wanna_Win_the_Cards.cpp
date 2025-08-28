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
vector<vector<vector<int>>> sg(101, vector<vector<int>>(101, vector<int>(101, -1)));

bool dfs(int n, int m, int k)
{
     if (k >= m)
     {
          sg[n][m][k] = 1;
          return 1;
     }

     if (sg[n][m][k] != -1)
          return sg[n][m][k];

     for (int i = 2; i <= k; ++i)
     {
          if (dfs(n, m - i, k) == false)
          {
               sg[n][m][k] = 1;
               return 1;
          }
          else if (dfs(n - 1, m - i + 1, k) == false)
          {
               sg[n][m][k] = 1;
               return 1;
          }
     }
     sg[n][m][k] = 0;
     return 0;
}
void solve()
{
     int n, k;
     cin >> n >> k;
     bool ok = dfs(n, n, k);
     if (ok)
          cout << "Blueberry\n";
     else
          cout << "Strawberry\n";
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
