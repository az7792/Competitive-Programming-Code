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
     int n, m, l;
     cin >> n >> m >> l;
     vector<int> a(n);
     vector<vector<int>> f(l, vector<int>(m));
     for (int i = 0; i < n; ++i)
          cin >> a[i];

     for (int i = 0; i < l; ++i)
          for (int j = 0; j < m; ++j)
               for (int k = i; k < n; k += l)
                    f[i][j] += (j - a[k] + m) % m;

     vector<vector<int>> dp(l, vector<int>(m, 2e9));

     for (int i = 0; i < m; ++i)
          dp[0][i] = f[0][i];

     for (int i = 1; i < l; ++i)
     {
          for (int j = 0; j < m; ++j)
          {
               for (int k = 0; k < m; ++k)
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + f[i][(j - k + m) % m]); //(k+x)%m = j
          }
     }

     cout << dp[l - 1][0];
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
